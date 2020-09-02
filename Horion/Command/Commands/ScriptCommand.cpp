#include "ScriptCommand.h"

ScriptCommand::ScriptCommand() : IMCCommand("script", "Manage scripts", "<load|unloadall>") {
}

ScriptCommand::~ScriptCommand() {
}

bool ScriptCommand::execute(std::vector<std::string>* args) {
	assertTrue(args->size() >= 2);
	std::string action = args->at(1);
	if (action == "load") {
		HorionDataPacket packet;
		packet.cmd = CMD_FOLDERCHOOSER;
		auto temp = std::shared_ptr<unsigned char[]>(new unsigned char[300]);
		packet.data.swap(temp);
		memset(packet.data.get(), 0, 300);
		strcpy_s((char*)packet.data.get(), 200, "{\"title\": \"Select a Script Folder\", \"filter\":\".js\"}");
		packet.dataArraySize = (int)strlen((char*)packet.data.get());
		return true;
	} else if (action == "unloadall") {
		scriptMgr.unloadAllScripts();
		return true;
	}
	

	return false;
}
