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

#include "../Config/Config.h"
#include "../shared.h"

namespace settings {
	// Initializes the data structure for Platinum
	void init(std::string bdsPath);

	// Gets the path of the files of Platinum
	std::string& getPath();

	Config* getSigCache();
	Config* getSettings();

	std::string getFunction(std::string pdbFunction, bool autoHandle = true);

	int getModuleInt(std::string nid, std::string item);
	bool getModuleBool(std::string nid, std::string item);
	float getModuleFloat(std::string nid, std::string item);
}