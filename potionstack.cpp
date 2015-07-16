#include "potionstack.h"
#define NULL 0

PotionStack::PotionStack() {
    _first = NULL;
    _stackSize = 0;
    return;
}

void PotionStack::chainDelete() {
    PotionNode *currentNode = _first;
    PotionNode *tempNode;

    while(currentNode) {
        tempNode = currentNode;
	currentNode = currentNode->getNext();
	delete tempNode;
    }

    _first = NULL;
    _stackSize = 0;
    return;
}
PotionStack::~PotionStack() {
    chainDelete();
    return;
}

PotionStack::PotionStack(const PotionStack& originalStack) {
    *this = originalStack;
    return;
}

PotionStack& PotionStack::operator =(const PotionStack& originalStack) {
    // Delete the old queue to avoid memory leaks.
    chainDelete();

    PotionNode *currentNode;
    PotionNode *otherNode = originalStack.getFront();

    while(otherNode) {
        currentNode = new PotionNode;
	if (currentNode) {
	    if(otherNode == originalStack.getFront()) {
                _first = currentNode;
	    }

	    currentNode = otherNode;
	    otherNode = otherNode->getNext();
	    _stackSize++;
	}
    }
    return *this;
}


PotionNode* PotionStack::getFront() const {
    return _first;
}

void PotionStack::pushFront(const Potion& newPotion) {
    PotionNode *newNode = new PotionNode;
    newNode->setPotion(newPotion);

    newNode->setNext(_first);
    _first = newNode;

    _stackSize++;

    return;
}

Potion PotionStack::popFront() {
    Potion poppedPotion;
    if(_stackSize > 0) {
	poppedPotion = _first->getPotion();
        // Store _first's original value so that it can be deleted.
        PotionNode* firstPtr = _first;

        // Remove _first from the stack by making _first equal to the second value.
        _first = _first->getNext();
	_stackSize--;

        delete firstPtr;
    }

    if(_stackSize == 0) {
	_first = NULL;
    }

    return poppedPotion; // Returns UNKNOWN potion if _first doesn't exist.
}

int PotionStack::getSize() {
    return _stackSize;
}

void PotionStack::printAll() {
    PotionNode *currentNode = _first;

    while(currentNode) {
	std::cout << currentNode->getPotion();
	currentNode = currentNode->getNext();
    }
    return;
}
