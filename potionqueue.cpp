Potion potionQueue::getFront() {
    return _first->getPotion();
}

Potion potionQueue::getBack() {
    return _last->getPotion();
}

void potionQueue::pushBack(potionNode* newNode) {
    if(_last) {
        _last->setNext(newNode);
        newNode->setNext(NULL);
        _last = newNode;
    }

    // If _last is NULL, the queue is empty.

    else {
        _first = newNode;
        _last = newNode;
    }

    return;
}

Potion potionQueue::popFront() {
    if(_first == NULL) {
    Potion poppedPotion = _first->getPotion();

    // Store _first's original value so that it can be deleted.
    potionNode* firstPtr = _first;

    // Remove _first from the queue by making _first equal to the second value.
    _first = first->getNext();

    delete firstPtr;
    return poppedPotion;
}
