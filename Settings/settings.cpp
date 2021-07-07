/*
*
* ------------------------------\
*          Platinum             |
*  Bedrock Dedicated Server     |
*  mod for enhancements and     |
*  more customization.          |
* ------------------------------/
*
* This is Free Software: You can edit and distribute it
* under the MIT license.
* author: PlatinumBDS's contributors
* link: https://github.com/Imrglop/PlatinumBDS
*/

#include "settings.h"
#include <fstream>

using std::ifstream;
using std::ofstream;

std::string dirPath;

std::shared_ptr<Config> currentSigCache;

std::shared_ptr<Config> cSettings;
std::shared_ptr<Config> cSigCache;
std::shared_ptr<Config> cLegacySigCache;

bool isLegacyVersion = false;

void settings::init(std::string bdsPath)
{
	dirPath = bdsPath + "\\Platinum";
	BOOL dirResult = CreateDirectoryA(dirPath.c_str(), NULL);
	if (dirResult == FALSE) {
		DWORD err = GetLastError();
		if (err != ERROR_ALREADY_EXISTS) {
			lerr("Could not create Platinum directory!\n");
			return;
		}
	}
	// -------------- CONFIG INITIALIZE --------------

	cSettings			=	std::make_shared<Config>((dirPath + "\\settings.txt"), "");
	cSigCache			=	std::make_shared<Config>((dirPath + "\\sigcache.txt"), "");
	cLegacySigCache		=	std::make_shared<Config>((dirPath + "\\sigcache_LEGACY.txt"), "");
	

	bool enabled = cSettings->load();
	if (!enabled) {
		lerr("Could not load settings file!");
		return;
	}

	isLegacyVersion = cSettings->getBool("legacy-bds-version");

	enabled = cSigCache->load();
	if (!enabled && !isLegacyVersion) {
		lerr("Could not load sigcache!");
		return;
	}

	enabled = cLegacySigCache->load();
	if (!enabled && isLegacyVersion) {
		lerr("Could not load sigcache for legacy verisons!");
		return;
	}

	// ----------------- INTERPRET SETTINGS ---------------------

	currentSigCache = isLegacyVersion ? cLegacySigCache : cSigCache;
}

std::string& settings::getPath()
{
	return std::ref(dirPath);
}

std::shared_ptr<Config> settings::getSigCache()
{
	return currentSigCache;
}

std::string settings::getFunction(std::string functionName, bool autoHandle)
{
	std::string sig = currentSigCache->getString(functionName);
	if (sig == "") {
#ifdef PLATINUM_DBG
		ldbg(functionName << " dead");
#endif
		if (autoHandle) {
			lerr("Couldn't find function " << functionName << " in sig cache!\n Make sure you're up to date with those files.");
			throw std::exception("Couldn't get mod function signature.");
		}
	}
	return sig;
}

int settings::getModuleInt(std::string nid, std::string item)
{
	return cSettings->getInteger(nid + ":" + item);
}

bool settings::getModuleBool(std::string nid, std::string item)
{
	return cSettings->getBool(nid + ":" + item);
}

float settings::getModuleFloat(std::string nid, std::string item)
{
	return cSettings->getNumber(nid + ":" + item);
}

std::shared_ptr<Config> settings::getSettings() {
	return cSettings;
}
