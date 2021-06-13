#pragma once
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

#include "../Module.h"
#include <vector>

class C_Command {
public:
	std::string str;
	int timesToExecute;
	inline C_Command(std::string command, int timesToExecute = 1) {
		this->str = command;
		this->timesToExecute = timesToExecute;
	}
};

class SignCommand : public Module
{
private:
	std::map<Vec3*, C_Command*> signsAndCommands;
public:
	SignCommand();
	bool enable() override;
	void disable() override;
};

