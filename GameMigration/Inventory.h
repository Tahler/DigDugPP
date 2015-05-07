
#ifndef INVENTORY_H
#define INVENTORY_H

/*
	1. COPPER
	2. IRON
	3. SILVER
	4. SAPPHIRE
	5. RUBY
	6. EMERALD
	7. GOLD
	8. DIAMOND
*/
class Inventory
{
private:
	
	int items[8];
	

public:
	Inventory() : 
		maxSize(10) // default size is 10
	{};
	Inventory(int invSize, int items[8], int money);

	int maxSize;
	int money;
	int size();
	bool isFull();
	void empty();
	void emptyMinerals();

	void sellMinerals();

	void addItem(int);
	void addCopper();
	void addIron();
	void addSilver();
	void addSapphire();
	void addRuby();
	void addEmerald();
	void addGold();
	void addDiamond();

	int getItemAmount(int);
	int getCopperAmount();
	int getIronAmount();
	int getSilverAmount();
	int getSapphireAmount();
	int getRubyAmount();
	int getEmeraldAmount();
	int getGoldAmount();
	int getDiamondAmount();
};

#endif