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

Config* currentSigCache = nullptr;

Config* lpSettings = nullptr;
Config* lpSigCache = nullptr;
Config* lpLegacySigCache = nullptr;

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

	lpSettings			=	new Config((dirPath + "\\settings.txt"), "");
	lpSigCache			=	new Config((dirPath + "\\sigcache.txt"), "");
	lpLegacySigCache	=	new Config((dirPath + "\\sigcache_LEGACY.txt"), "");
	

	bool enabled = lpSettings->load();
	if (!enabled) {
		lerr("Could not load settings file!");
		return;
	}

	isLegacyVersion = lpSettings->getBool("legacy-bds-version");

	enabled = lpSigCache->load();
	if (!enabled && !isLegacyVersion) {
		lerr("Could not load sigcache!");
		return;
	}

	enabled = lpLegacySigCache->load();
	if (!enabled && isLegacyVersion) {
		lerr("Could not load sigcache for legacy verisons!");
		return;
	}

	// ----------------- INTERPRET SETTINGS ---------------------

	currentSigCache = isLegacyVersion ? lpLegacySigCache : lpSigCache;
}

std::string& settings::getPath()
{
	return std::ref(dirPath);
}

Config* settings::getSigCache()
{
	return currentSigCache;
}

std::string settings::getFunction(std::string pdbFunction, bool autoHandle)
{
	std::string sig = currentSigCache->getString(pdbFunction);
	if (autoHandle && sig == "") {
		lerr("Couldn't find function " << pdbFunction << " in sig cache!\n Make sure you're up to date with those files.");
		throw std::exception("Couldn't get mod function signature.");
	}
	return sig;
}

int settings::getModuleInt(std::string nid, std::string item)
{
	return lpSettings->getInteger(nid + ":" + item);
}

bool settings::getModuleBool(std::string nid, std::string item)
{
	return lpSettings->getBool(nid + ":" + item);
}

float settings::getModuleFloat(std::string nid, std::string item)
{
	return lpSettings->getNumber(nid + ":" + item);
}

Config* settings::getSettings() {
	return lpSettings;
}