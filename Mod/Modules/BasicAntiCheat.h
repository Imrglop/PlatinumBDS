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
#include "../Module.h"

class BasicAntiCheat : public Module
{
private:
	bool isAntiCrasher = false;
	bool isAntiXP = false;
public:
	BasicAntiCheat();
	bool enable() override;
	void disable() override;
};

