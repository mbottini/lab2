// potion.h
// Michael Bottini
// Created for CS260
// July 8, 2015
// Potion header file for apothecary program.

#ifndef POTION_H
#define POTION_H

#include "main.h"
#include <iostream>

class Potion {
    private:
        PotionType _type;

    public:
        Potion(PotionType type = UNKNOWN);
	Potion(const Potion& originalPotion);
	Potion& operator =(const Potion& originalPotion);
        PotionType GetType() const;
	friend std::ostream& operator <<(std::ostream& out, const Potion& pt);
};

class PotionNode {
    private:
        Potion _potion;
        PotionNode *_nextPotion;

    public:
        PotionNode();
	PotionNode(const PotionNode& originalNode);
	PotionNode& operator =(const PotionNode& originalNode);
        const Potion& getPotion() const;
        PotionNode* getNext();
        void setPotion(const Potion& newPotion);
	void setNext(PotionNode* newNode);
};

#endif
