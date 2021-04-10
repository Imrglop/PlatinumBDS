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

#pragma once
#include "../shared.h"
#include "hook_def.h"

#define nlog(item) _PLOG(this->name, item)
#define nerr(item) _PERR(this->name, item)

class Module
{
public:
	bool enabled = false;
	const char* nid = "prototype-module";
	const char* name = "Prototype Module";

	Module(const char* nid, const char* name);

	virtual bool enable();
	virtual void disable();
	virtual void tick();
};
