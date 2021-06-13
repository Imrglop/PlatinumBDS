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

#include "SignCommand.h"

SignCommand::SignCommand() : Module(nid, name) {
	this->name = "SignCommand";
	this->nid = "sign-command";
}

bool SignCommand::enable() {
	auto gaming = this->getConfig()->getIntegerList("testing 123");
	for (int i = 0; i < gaming.size(); i++) {
		llog(i << " :: " << gaming[i]);
	}
	return true;
}

void SignCommand::disable() {

}