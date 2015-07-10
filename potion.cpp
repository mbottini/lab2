// potion.cpp
// Michael Bottini
// Created for CS260
// July 8, 2015
// Potion implementation file for apothecary program.

#include "potion.h"

Potion::Potion(PotionType type) {
    _type = type;
    return;
}

PotionType Potion::GetType() {
    return _type;
}

PotionNode::PotionNode() {


Potion& PotionNode::getPotion() {
    return _potion;
}

Potion& PotionNode::getNext() {
    return _nextPotion;
}
