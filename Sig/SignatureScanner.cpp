// The pattern scanner from github.com/Imrglop/SignatureScanner
// Slightly modified for PlatinumBDS

#include <vector>
#include <sstream>
#include <string>
#include "SignatureScanner.h"
#include <Psapi.h>

#include "../shared.h"

using std::string;

// SA_utils.h/cpp
namespace sa_utils_ex {
	std::vector<std::string> splitString(std::string str, char delim) {
		std::vector<std::string> retVal = {};
		std::istringstream split(str);
		for (std::string each; std::getline(split, each, delim); retVal.push_back(each));
		return retVal;
	}
}

SignatureScanner::SignatureScanner(uintptr_t start, uintptr_t end)
{
	this->startAddress = start;
	this->endAddress = end;
}

SignatureScanner::SignatureScanner(HANDLE hProcess, uintptr_t start, uintptr_t end)
{
	this->startAddress = start;
	this->endAddress = end;
	this->hProcess = hProcess;
}

uintptr_t SignatureScanner::scan(std::string pattern)
{
	using namespace sa_utils_ex;
	if (pattern == "") return NULL;
	auto sstr = splitString(pattern, '+');
	int offset = 0;
	if (sstr.size() > 1) {
		offset = std::stoi(sstr[0]);
		pattern = sstr[1];
	}
	std::vector<std::string> strbytes = splitString(pattern, ' ');
	std::vector<int> signature = {};
	for (unsigned int i = 0; i < strbytes.size(); i++) {
		std::string str = strbytes[i];
		if (str == "??" || str == "?") {
			signature.push_back(-1);
		}
		else {
			signature.push_back((int)(std::stoul(str, nullptr, 16)));
		}
	}

	size_t sigSize = signature.size();
	uintptr_t end = this->endAddress - signature.size();
	size_t j = 0;
#define BDEREF(x) *((byte*)x)
	for (size_t i = this->startAddress; i < end; i++)
	{
		for (true; j < signature.size(); j++)
		{
			if (i + j >= end) {
#if defined(PLATINUM_DBG)
				lwarn("Signature dead: " << pattern);
#endif
				return NULL;
			}
			if (signature[j] != -1 && BDEREF((i + j)) != signature[j]) break;
		}
		if (j >= signature.size()) {
			return i + offset;
		}
	}
#if defined(PLATINUM_DBG)
	lwarn("Signature dead: " << pattern);
#endif
	return 0;
}
#undef BDEREF

uintptr_t SignatureScanner::scanEx(std::string pattern)
{
	std::vector<std::string> strbytes = sa_utils_ex::splitString(pattern, ' ');
	std::vector<int> signature = {};
	for (unsigned int i = 0; i < strbytes.size(); i++) {
		std::string str = strbytes[i];
		if (str == "??" || str == "?") {
			signature.push_back(-1);
		}
		else {
			signature.push_back((int)(std::stoul(str, nullptr, 16)));
		}
	}
	size_t sigSize = signature.size();
	uintptr_t end = this->endAddress - signature.size();
	size_t j;
	uintptr_t i = this->startAddress;
#define RPM(addr, res) ReadProcessMemory(this->hProcess, (LPVOID)addr, &res, sizeof(res), 0)
	for (size_t i = this->startAddress; i < end; i++)
	{
		j = 0;
		for (true; j < signature.size(); j++)
		{
			if (signature[j] != -1) {
				byte val = 0;
				RPM((i + j), val);
				if (val != signature[j]) break;
			}
		}
		if (j >= signature.size() - 1) {
			return i;
		}
	}
	return NULL;
}
#undef RPM