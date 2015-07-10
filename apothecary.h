// apothecary.h
// Michael Bottini
// Created for CS260
// July 8, 2015
// Apothecary header file for apothecary program.

class Apothecary {
    private:
        PotionNode *_orderQueueHead;
        PotionNode *_potionStackHead;
        int _maxQueueSize;
        int _maxStackSize;
        int _orderQueueSize;
        int _potionStackSize;

    public:
        Apothecary(int maxQueue, int maxStack);
        ~Apothecary();

