// potionqueue.h
// Michael Bottini
// Created for CS 260
// Header file for potion queue, used to store orders for the apothecary.

#ifndef POTIONQUEUE_H
#define POTIONQUEUE_H

#include "potion.h"
#include <iostream>

class PotionQueue {
    private:
        PotionNode *_first;
        PotionNode *_last;
	int _queueSize;

    public:
	PotionQueue();
	void chainDelete();
	~PotionQueue();
	PotionQueue(const PotionQueue& originalQueue);
	PotionQueue& operator =(const PotionQueue& originalQueue);


        PotionNode* getFront() const;
	PotionNode* getBack() const;
        void pushBack(const Potion& newPotion);
        Potion popFront();
	int getSize();
	void printAll();
}; 

#endif
