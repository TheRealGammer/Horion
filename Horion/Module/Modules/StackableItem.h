#pragma once
#include "Module.h"

struct StackableItem : public IModule 
{
	int maxStackSize;

	StackableItem();
	~StackableItem(){};

	virtual const char* getModuleName() override;
	virtual void onTick(C_GameMode* gm) override;
};
