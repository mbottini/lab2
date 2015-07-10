// potion.h
// Michael Bottini
// Created for CS260
// July 8, 2015
// Potion header file for apothecary program.

#ifndef POTION_H
#define POTION_H

#include "main.h"

class Potion {
    private:
        PotionType _type;

    public:
        Potion(PotionType type = UNKNOWN);
        PotionType GetType();
};

class PotionNode {
    private:
        Potion _potion;
        Potion _*nextPotion;

    public:
        PotionNode();
        Potion& getPotion();
        Potion* getNext();
        void setPotion(Potion newPotion);
};

#endif
