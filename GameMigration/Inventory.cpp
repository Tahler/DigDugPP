
#include "Inventory.h"
#include "Character.h"
#include <string>

enum Minerals
{
	COPPER, IRON, SILVER, SAPPHIRE, RUBY, EMERALD, GOLD, DIAMOND
};

Inventory::Inventory(int invSize, int copy[8], int money, int ladderCount)
{
	maxSize = invSize;
	ladderCount = 0;
	int length = sizeof(items) / sizeof(*items);
	for (int i = 0; i < length; ++i)
	{
		items[i] = copy[i];
	}

	Inventory::money = money;
	Inventory::ladderCount = ladderCount;
}

int Inventory::size()
{
	int count = 0;
	int length = sizeof(items) / sizeof(*items);
	for (int i = 0; i < length; ++i) count += items[i];
	return count;
}
bool Inventory::isFull()
{
	return size() >= maxSize;
}
void Inventory::emptyMinerals()
{
	int length = sizeof(items) / sizeof(*items);
	for (int i = 0; i < length; ++i) items[i] = 0;
}

void Inventory::sellMinerals()
{
	const static int VALUES[8] = { 30, 50, 70, 90, 120, 150, 180, 200 };

	int length = sizeof(items) / sizeof(*items);
	for (int i = 0; i < length; ++i)
	{
		money += items[i] * VALUES[i];
	}
	emptyMinerals();
}

void Inventory::empty()
{
	emptyMinerals();
	money = 0;
	ladderCount = 0;
}

void Inventory::addItem(int i)
{
	if (!isFull())
	{
		items[i]++;

		string s;
		Minerals m = (Minerals) i;
		switch (m)
		{
		case COPPER:
			s = "Copper";
			break;
		case IRON:
			s = "Iron";
			break;
		case SILVER:
			s = "Silver";
			break;
		case SAPPHIRE:
			s = "Sapphire";
			break;
		case RUBY:
			s = "Ruby";
			break;
		case EMERALD:
			s = "Emerald";
			break;
		case GOLD:
			s = "Gold";
			break;
		case DIAMOND:
			s = "Diamond";
			break;
		default:
			s = "Unknown";
		}
		Character::notification = "+1 " + s;
	}
	else Character::notification = "Inventory full.";
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
