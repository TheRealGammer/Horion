#include "StackableItem.h"

StackableItem::StackableItem() : IModule(0x0, Category::PLAYER, "Stack items you normally wouldn't be able to stack (e. g. swords)") 
{
	this->registerIntSetting("MaxStackSize", &maxStackSize, 64, 1, 255);
}

const char* StackableItem::getModuleName()
{
	return ("StackableItem");
}

void StackableItem::onTick(C_GameMode* gm) {
	C_PlayerInventoryProxy* supplies = g_Data.getLocalPlayer()->getSupplies();
	C_Inventory* a = supplies->inventory;
	for (int i = 0; i < 36; i++) {
		C_ItemStack* stack = a->getItemStack(i);
		if (stack->item != NULL) {
			C_Item* item = *stack->item;
			item->setStackedByData(true);
			item->setMaxStackSize(maxStackSize);
		}
	}
}
