
#include "Inventory.h"

Inventory::Inventory(int invSize, int copy[8], int money)
{
	maxSize = invSize;

	int length = sizeof(items) / sizeof(*items);
	for (int i = 0; i < length; ++i)
	{
		items[i] = copy[i];
	}

	Inventory::money = money;
}

int Inventory::size()
{
	int count = 0;
	int length = sizeof(items) / sizeof(*items);
	for (int i = 0; i < length; ++i) count += items[i];
	return count;
}

void Inventory::addItem(int i)
{
	items[i]++;
}
void Inventory::addCopper()
{
	addItem(0);
}
void Inventory::addIron()
{
	addItem(1);
}
void Inventory::addSilver()
{
	addItem(2);
}
void Inventory::addSapphire()
{
	addItem(3);
}
void Inventory::addRuby()
{
	addItem(4);
}
void Inventory::addEmerald()
{
	addItem(5);
}
void Inventory::addGold()
{
	addItem(6);
}
void Inventory::addDiamond()
{
	addItem(7);
}

int Inventory::getItemAmount(int i)
{
	return items[i];
}
int Inventory::getCopperAmount()
{
	return getItemAmount(0);
}
int Inventory::getIronAmount()
{	
	return getItemAmount(1);
}
int Inventory::getSilverAmount()
{	
	return getItemAmount(2);
}
int Inventory::getSapphireAmount()
{	
	return getItemAmount(3);
}
int Inventory::getRubyAmount()
{	
	return getItemAmount(4);
}
int Inventory::getEmeraldAmount()
{	
	return getItemAmount(5);
}
int Inventory::getGoldAmount()
{	
	return getItemAmount(6);
}
int Inventory::getDiamondAmount()
{	
	return getItemAmount(7);
}
