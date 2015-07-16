// potion.cpp
// Michael Bottini
// Created for CS260
// July 8, 2015
// Potion implementation file for apothecary program.

#include "potion.h"
#include "main.h"

#define NULL 0

Potion::Potion(PotionType type) {
    _type = type;
    return;
}

Potion::Potion(const Potion& originalPotion) {
    *this = originalPotion;
    return;
}

Potion& Potion::operator =(const Potion& originalPotion) {
    _type = originalPotion.GetType();
    return *this;
}

PotionType Potion::GetType() const {
    return _type;
}

PotionNode::PotionNode() {
    // Initial potion is set to UNKNOWN by Potion constructor.
    _nextPotion = NULL;
    return;
}

PotionNode::PotionNode(const PotionNode& originalNode) {
    *this = originalNode;
    return;
}

PotionNode& PotionNode::operator =(const PotionNode& originalNode) {
    _potion = originalNode.getPotion();
    _nextPotion = NULL;
    return *this;
}


const Potion& PotionNode::getPotion() const {
    return _potion;
}

std::ostream& operator <<(std::ostream& out, const Potion& pt) {
    out << "Potion of " << PotionTypeString(pt.GetType()) << "\n";
    return out;
}

PotionNode* PotionNode::getNext() {
    return _nextPotion;
}

void PotionNode::setPotion(const Potion& newPotion) {
    _potion = newPotion;
    return;
}

void PotionNode::setNext(PotionNode* newNode) {
    _nextPotion = newNode;
    return;
}
