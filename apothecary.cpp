// apothecary.cpp
// Michael Bottini
// Created for CS260
// July 15, 2015
// Implementation file for apothecary class.

#include "Apothecary.h"

Apothecary::Apothecary(int maxQueue, int maxStack) {
    _maxQueueSize = maxQueue;
    _maxStackSize = maxStack;
    return;
}

bool Apothecary::OrderPotion(PotionType potion) {
    Potion newPotion(potion);
    bool addedPotion = false;
    if(_orderQueue.getSize() < _maxQueueSize) {
        _orderQueue.enqueue(newPotion);
	addedPotion = true;
    }

    return addedPotion;
}

int Apothecary::MakePotions() {
    int potionsMade = 0;
    Potion currentPotion;

    while(_potionStack.getSize() < _maxStackSize && _orderQueue.getSize() > 0) {
	currentPotion = _orderQueue.popFront();
	_potionStack.pushFront(currentPotion);
	std::cout << "Made a " << PotionTypeString(currentPotion.GetType()) << " potion.\n";
	potionsMade++;
    }


    if(_orderQueue.getSize() > 0 && _potionStack.getSize() == _maxStackSize) {
        std::cout << "The shelf of potions is full.  You can't make any more "
		  << "until somebody buys some.\n";
    }
 
    return potionsMade;
}

bool Apothecary::BuyPotion(Potion& potion) {

    Potion poppedPotion;
    bool boughtPotion = false;
    if(_potionStack.getSize() > 0) {
	poppedPotion = _potionStack.popFront();
	potion = poppedPotion;
	boughtPotion = true;
    }

    return boughtPotion;
}
	    
