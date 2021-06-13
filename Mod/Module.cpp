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

#include "Module.h"
#include "../Settings/settings.h"
#include <iostream>

Module::Module(const char* nid, const char* name) {
	this->nid = nid;
	this->name = name;
}

bool Module::enable() 
{
	nlog("Enabling Module");
	return true;
}

void Module::disable() {
	nlog("Disabling Module");
}

void Module::tick()
{
}

Config* Module::getConfig(std::string defaults)
{
	// --- DIRECTORY ---
	using namespace settings;
	std::string fol = getPath() + std::string("\\Modules");
	BOOL status = CreateDirectoryA(fol.c_str(), NULL);
	if (!status) {
		DWORD err = GetLastError();
		if (err != ERROR_ALREADY_EXISTS) {
			return nullptr;
		}
	}
	// -- CONFIG --
	
	Config* config = new Config(fol + "\\" + this->name, defaults);
	return config;
}
