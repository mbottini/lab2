// potionstructure.cpp
// Michael Bottini
// Created for CS 260
// Implementation file for potion structure base class.

#include "potionstructure.h"

PotionStructure::PotionStructure() {
    _first = NULL;
    _last = NULL;
    _size = 0;
    return;
}

void PotionStructure::chainDelete() {
    PotionNode *currentNode = _first;
    PotionNode *tempNode;

    while(currentNode) {
        tempNode = currentNode;
	currentNode = currentNode->getNext();
	delete tempNode;
    }

    _first = NULL;
    _last = NULL;
    _size = 0;
    return;
}

PotionStructure::~PotionStructure() {
    chainDelete();
    return;
}

PotionStructure::PotionStructure(const PotionStructure& originalStructure) {
    *this = originalStructure;
    return;
}

PotionStructure& PotionStructure::operator =(const PotionStructure& originalStructure) {
    // If you're setting it equal to itself, do nothing.
    if(*this == originalStructure) {
        return *this;                
    }

    // Otherwise, we delete the old queue to avoid memory leaks.
    chainDelete();

    PotionNode *currentNode;
    PotionNode *otherNode = originalStructure.getFront();

    while(otherNode) {
	currentNode = new PotionNode;
	if(currentNode) {
	    if(otherNode == originalStructure.getFront()) {
	        _first = currentNode;
	    }

	    else if(otherNode == originalStructure.getBack()) {
		_last = currentNode;
	    }

	    currentNode->setPotion(otherNode->getPotion());
	    otherNode = otherNode->getNext();
	}
    }

    return *this;
}

PotionNode* PotionStructure::getFront() const {
    return _first;
}

PotionNode* PotionStructure::getBack() const {
    return _last;
}

Potion PotionStructure::popFront() {
    Potion poppedPotion;
    PotionNode *firstPtr = _first;

    if(_first) {
        poppedPotion = _first->getPotion();
	_first = _first->getNext();
	_size--;

	// If _first == _last, popping it empties the list.
	if(firstPtr == _last) {
	    _last = NULL;
	    _first = NULL;
	}

	delete firstPtr;
    }

    // Returns UNKNOWN potion if an empty list is popped.
    return poppedPotion;
}

void PotionStructure::pushBack(const Potion& newPotion) {
    PotionNode *newNode = new PotionNode;
    if(newNode) {
        newNode->setPotion(newPotion);
	if(_last) {
	    _last->setNext(newNode);
	    _last = newNode;
	}

	// if _last is NULL, the queue is empty.
	
	else {
	    _first = newNode;
	    _last = newNode;
	}

	_size++;
    }

    return;
}

void PotionStructure::pushFront(const Potion& newPotion) {
    PotionNode *newNode = new PotionNode;
    
    if(newNode) {
	newNode->setPotion(newPotion);
	newNode->setNext(_first);
	_first = newNode;
	_size++;

	if(_last == NULL) {
	    _last = _first;
	}
    }

    return;
}
    

void PotionStructure::printAll() {
    PotionNode *currentNode = _first;

    while(currentNode) {
        std::cout << currentNode->getPotion();
	currentNode = currentNode->getNext();
    }

    return;
}

int PotionStructure::getSize() {
    return _size;
}

bool PotionStructure::operator ==(const PotionStructure& otherStructure) const {
    // All lists are deep copied, so we can define a list as "equal" if the
    // _first and _last pointers are the same.
    
    return _first == otherStructure.getFront() && _last == otherStructure.getBack();
}
        
