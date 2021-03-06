// apothecary.h
// Michael Bottini
// Created for CS260
// July 8, 2015
// Apothecary header file for apothecary program. Named "Apothecary.h"
// because the provided main program capitalizes it.

#include "potion.h"
#include "potionstructure.h"

class Apothecary {
    private:
	PotionStructure _orderQueue;
	PotionStructure _potionStack;
        int _maxQueueSize;
        int _maxStackSize;

    public:
        Apothecary(int maxQueue, int maxStack);
	bool OrderPotion(PotionType potion);
	int MakePotions();
	bool BuyPotion(Potion& potion);
};

