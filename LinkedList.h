#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Node class definition
class Node {
public:
    int data;         // Data held by the node
    Node* next;       // Pointer to the next node

    // Constructor to initialize a node with given value
    Node(int val) : data(val), next(nullptr) {}
};

// LinkedList class definition
class LinkedList {
public:
    LinkedList();     // Constructor
    ~LinkedList();    // Destructor

    // Member functions
    void insertAtFirst(int val);
    void insertAtLast(int val);
    void insertByPos(int pos, int newval);
    void deleteAtFirst();
    void deleteAtLast();
    void deleteElementByPos(int pos);
    void deleteElementByValue(int val);
    int& getElementByPosition(int pos);
    bool searchElementByValue(int val);
    void updateElement(int pos, int newVal);
    int ReadElement(int pos);
    bool isEmpty();
    void makeListEmpty();
    void display();
    void traverse();

private:
    Node* head;       // Pointer to the first node in the list
};

#endif // LINKEDLIST_H
