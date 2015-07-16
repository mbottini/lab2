// potionqueue.h
// Michael Bottini
// Created for CS 260
// Header file for potion stack, used to store potions for the apothecary.

#ifndef POTIONSTACK_H
#define POTIONSTACK_H

#include "potion.h"
#include <iostream>

class PotionStack {
    private:
        PotionNode *_first;
	int _stackSize;

    public:
	PotionStack();
	void chainDelete();
	~PotionStack();
	PotionStack(const PotionStack& originalStack);
	PotionStack& operator =(const PotionStack& originalStack);


        PotionNode* getFront() const;
        void pushFront(const Potion& newPotion);
        Potion popFront();

	int getSize();
	void printAll();
}; 

#endif
