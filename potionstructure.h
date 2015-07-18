// potionstructure.h
// Michael Bottini
// Created for CS 260
// Header file for potion structure base class.

#ifndef POTIONSTRUCTURE_H
#define POTIONSTRUCTURE_H

#include "potion.h"
#include <iostream>

class PotionStructure {
    private:
        PotionNode *_first;
	PotionNode *_last;
	int _size;

    public:
	PotionStructure();
	void chainDelete();
	~PotionStructure();
	PotionStructure(const PotionStructure& OriginalStructure);
	PotionStructure& operator =(const PotionStructure& originalStructure);
	PotionNode* getFront() const;
	PotionNode* getBack() const;
	void pushBack(const Potion& newPotion);
	void pushFront(const Potion& newPotion);
	Potion popFront();
	void printAll();
	int getSize();
	bool operator ==(const PotionStructure& otherStructure) const;
};

#endif
