#include "potionqueue.h"
#define NULL 0

PotionQueue::PotionQueue() {
    _first = NULL;
    _last = NULL;
    _queueSize = 0;
    return;
}

void PotionQueue::chainDelete() {
    PotionNode *currentNode = _first;
    PotionNode *tempNode;

    while(currentNode) {
        tempNode = currentNode;
	currentNode = currentNode->getNext();
	delete tempNode;
    }

    _first = NULL;
    _last = NULL;
    _queueSize = 0;
    return;
}
PotionQueue::~PotionQueue() {
    chainDelete();
    return;
}

PotionQueue::PotionQueue(const PotionQueue& originalQueue) {
    *this = originalQueue;
    return;
}

PotionQueue& PotionQueue::operator =(const PotionQueue& originalQueue) {
    // Delete the old queue to avoid memory leaks.
    chainDelete();

    PotionNode *currentNode;
    PotionNode *otherNode = originalQueue.getFront();

    while(otherNode) {
        currentNode = new PotionNode;
	if (currentNode) {
	    if(otherNode == originalQueue.getFront()) {
                _first = currentNode;
	    }

	    else if(otherNode == originalQueue.getBack()) {
	        _last = currentNode;
	    }

	    currentNode = otherNode;
	    otherNode = otherNode->getNext();
	}
    }
    return *this;
}


PotionNode* PotionQueue::getFront() const {
    return _first;
}

PotionNode* PotionQueue::getBack() const {
    return _last;
}

void PotionQueue::pushBack(const Potion& newPotion) {
    PotionNode *newNode = new PotionNode;
    newNode->setPotion(newPotion);
    if(_last) {
        _last->setNext(newNode);
        _last = newNode;
    }

    // If _last is NULL, the queue is empty.

    else {
        _first = newNode;
        _last = newNode;
    }

    _queueSize++;

    return;
}

Potion PotionQueue::popFront() {
    Potion poppedPotion;
    if(_first) {
	poppedPotion = _first->getPotion();
        // Store _first's original value so that it can be deleted.
        PotionNode* firstPtr = _first;

        // Remove _first from the queue by making _first equal to the second value.
        _first = _first->getNext();
	_queueSize--;

        delete firstPtr;
    }

    if(_queueSize == 0) {
	_first = NULL;
	_last = NULL;
    }

    return poppedPotion; // Returns UNKNOWN potion if _first doesn't exist.
}

void PotionQueue::printAll() {
    PotionNode *currentNode = _first;

    while(currentNode) {
        std::cout << currentNode->getPotion();
	currentNode = currentNode->getNext();
    }

    return;
}
int PotionQueue::getSize() {
    return _queueSize;
}
