// potionqueue.h
// Michael Bottini
// Created for CS 260
// Header file for potion queue, used to store orders for the apothecary.

#ifndef POTIONQUEUE_H
#define POTIONQUEUE_H

#include "potionnode.h"
#include "potion.h"
class potionQueue {
    private:
        potionNode *_first;
        potionNode *_last;

    public:
        Potion getFront();
        Potion getBack();
        void pushBack(potionNode* newNode);
        Potion popFront();
} 

#endif
