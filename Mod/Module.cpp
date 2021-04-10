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
