#include <iostream>
#include "LinkedList.h"
using namespace std;

// Constructor to initialize an empty list
LinkedList::LinkedList() : head(nullptr) {}

// Destructor to clear the list
LinkedList::~LinkedList() {
    makeListEmpty();
}

// Insert a new node with value `val` at the beginning of the list
void LinkedList::insertAtFirst(int val) {
    Node* newNode = new Node(val); // Create a new node
    if (isEmpty()) {
        head = newNode; // List is empty, new node is the head
    } else {
        newNode->next = head; // Point new node to the current head
        head = newNode;       // Update head to new node
    }
}

// Insert a new node with value `val` at the end of the list
void LinkedList::insertAtLast(int val) {
    Node* newNode = new Node(val); // Create a new node
    if (isEmpty()) {
        head = newNode; // List is empty, new node is the head
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode; // Append new node to the end
    }
}

// Insert a new node with value `newval` at position `pos`
void LinkedList::insertByPos(int pos, int newval) {
    if (pos < 0) {
        cout << "Invalid position" << endl;
        return;
    }

    Node* newNode = new Node(newval); // Create a new node

    if (pos == 0) {
        newNode->next = head; // Insert at the beginning
        head = newNode;
        return;
    }

    Node* currentNode = head;
    int count = 0;
    while (currentNode != nullptr && count < pos - 1) {
        currentNode = currentNode->next; // Traverse to the position before the insertion point
        count++;
    }

    if (currentNode == nullptr) {
        cout << "Position out of range" << endl;
        delete newNode;
        return;
    }

    newNode->next = currentNode->next; // Insert new node in the correct position
    currentNode->next = newNode;
}

// Delete the first node in the list
void LinkedList::deleteAtFirst() {
    if (!isEmpty()) {
        Node* temp = head; // Temporarily store the head
        head = head->next; // Update head to the next node
        delete temp;        // Delete the old head
    } else {
        cout << "List is empty" << endl;
    }
}

// Delete the last node in the list
void LinkedList::deleteAtLast() {
    if (isEmpty()) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head; // Only one node in the list
        head = nullptr;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;
    while (temp->next != nullptr) {
        prev = temp; // Track the node before the last node
        temp = temp->next; // Traverse to the last node
    }
    prev->next = nullptr; // Remove the last node
    delete temp;
}

// Delete the node at position `pos`
void LinkedList::deleteElementByPos(int pos) {
    if (isEmpty()) {
        cout << "List is empty" << endl;
        return;
    }

    if (pos < 0) {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 0) {
        deleteAtFirst(); // Delete the first node
        return;
    }

    Node* currentNode = head;
    Node* prev = nullptr;
    int count = 0;

    while (currentNode != nullptr && count < pos) {
        prev = currentNode;
        currentNode = currentNode->next; // Traverse to the node before the deletion point
        count++;
    }

    if (currentNode == nullptr) {
        cout << "Position out of range" << endl;
        return;
    }

    prev->next = currentNode->next; // Remove the node
    delete currentNode;
}

// Delete the node with value `val`
void LinkedList::deleteElementByValue(int val) {
    if (isEmpty()) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->data == val) {
        deleteAtFirst(); // If head node has the value
        return;
    }

    Node* currentNode = head;
    Node* prev = nullptr;

    while (currentNode != nullptr && currentNode->data != val) {
        prev = currentNode;
        currentNode = currentNode->next; // Traverse to find the node with the value
    }

    if (currentNode == nullptr) {
        cout << "Value not found" << endl;
        return;
    }

    prev->next = currentNode->next; // Remove the node
    delete currentNode;
}

// Get the reference to the data at position `pos`
int& LinkedList::getElementByPosition(int pos) {
    if (pos < 0) {
        throw out_of_range("Position out of range");
    }

    Node* temp = head;
    int count = 0;
    while (temp != nullptr && count < pos) {
        temp = temp->next; // Traverse to the position
        count++;
    }

    if (temp == nullptr) {
        throw out_of_range("Position out of range");
    }

    return temp->data;
}

// Search for a node with value `val`
bool LinkedList::searchElementByValue(int val) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == val) {
            return true; // Value found
        }
        temp = temp->next; // Traverse to the next node
    }
    return false; // Value not found
}

// Update the data at position `pos` to `newVal`
void LinkedList::updateElement(int pos, int newVal) {
    if (pos < 0) {
        cout << "Invalid position" << endl;
        return;
    }

    Node* temp = head;
    int count = 0;
    while (temp != nullptr && count < pos) {
        temp = temp->next; // Traverse to the position
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of range" << endl;
        return;
    }

    temp->data = newVal; // Update the value
}

// Read the data at position `pos`
int LinkedList::ReadElement(int pos) {
    if (pos < 0) {
        cout << "Invalid position" << endl;
        return -1;
    }

    Node* temp = head;
    int count = 0;
    while (temp != nullptr && count < pos) {
        temp = temp->next; // Traverse to the position
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of range" << endl;
        return -1;
    }

    return temp->data; // Return the value
}

// Check if the list is empty
bool LinkedList::isEmpty() {
    return head == nullptr;
}

// Make the list empty by deleting all nodes
void LinkedList::makeListEmpty() {
    while (!isEmpty()) {
        deleteAtFirst(); // Delete nodes one by one
    }
}

// Display all elements in the list
void LinkedList::display() {
    Node* temp = head;
    if (temp == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    while (temp != nullptr) {
        cout << temp->data << " "; // Print the value of each node
        temp = temp->next; // Move to the next node
    }
    cout << endl;
}

// Traverse and display the list
void LinkedList::traverse() {
    display(); // Simply call display
}
