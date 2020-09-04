#pragma once
#include "../ModuleManager.h"
#include "Module.h"

struct SmoothFont : public IModule {
	SmoothFont() : IModule('\0', Category::VISUAL, "Off: Minecraft font. On: Smooth font.") {}

	virtual const char* SmoothFont::getModuleName() override { return ("SmoothFont"); }
};
