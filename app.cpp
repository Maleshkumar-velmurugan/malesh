#include <iostream>
#include "LinkedList.h"

using namespace std;

// Function prototypes
void menu();
void handleUserChoice(int choice, LinkedList &list);

int main() {
    LinkedList list;  // Create a LinkedList object
    int choice;  // Variable to store the user's choice

    // Display the menu once
    menu();

    // Loop to handle user choices
    do {
        cout << "Enter your choice (or 15 to exit): ";
        cin >> choice;  // Get user input
        if (choice != 15) {
            handleUserChoice(choice, list);  // Handle the user's choice
        }
    } while (choice != 15);  // Continue until the user chooses to exit

    return 0;  // End of the program
}

// Function to display the menu
void menu() {
    cout << "\n----- Linked List Operations -----\n";
    cout << "1. Insert at First\n";
    cout << "2. Insert at Last\n";
    cout << "3. Insert at Position\n";
    cout << "4. Delete at First\n";
    cout << "5. Delete at Last\n";
    cout << "6. Delete by Position\n";
    cout << "7. Delete by Value\n";
    cout << "8. Search Element by Value\n";
    cout << "9. Get Element by Position\n";
    cout << "10. Read Element by Position\n";
    cout << "11. Update Element at Position\n";
    cout << "12. Display List\n";
    cout << "13. Traverse List\n";
    cout << "14. Check if List is Empty\n";
    cout << "15. Exit\n";
}

// Function to handle the user choice
void handleUserChoice(int choice, LinkedList &list) {
    int value, position;  // Variables to store user input

    switch (choice) {
        case 1:  // Insert at First
            cout << "Enter the value to insert at the beginning: ";
            cin >> value;
            list.insertAtFirst(value);  // Call the insertAtFirst function
            break;
        case 2:  // Insert at Last
            cout << "Enter the value to insert at the end: ";
            cin >> value;
            list.insertAtLast(value);  // Call the insertAtLast function
            break;
        case 3:  // Insert at Position
            cout << "Enter the position to insert: ";
            cin >> position;
            cout << "Enter the value to insert: ";
            cin >> value;
            list.insertByPos(position, value);  // Call the insertByPos function
            break;
        case 4:  // Delete at First
            cout << "Deleting the first element...\n";
            list.deleteAtFirst();  // Call the deleteAtFirst function
            break;
        case 5:  // Delete at Last
            cout << "Deleting the last element...\n";
            list.deleteAtLast();  // Call the deleteAtLast function
            break;
        case 6:  // Delete by Position
            cout << "Enter the position to delete: ";
            cin >> position;
            list.deleteElementByPos(position);  // Call the deleteElementByPos function
            break;
        case 7:  // Delete by Value
            cout << "Enter the value to delete: ";
            cin >> value;
            list.deleteElementByValue(value);  // Call the deleteElementByValue function
            break;
        case 8:  // Search Element by Value
            cout << "Enter the value to search: ";
            cin >> value;
            if (list.searchElementByValue(value)) {
                cout << "Element found in the list.\n";
            } else {
                cout << "Element not found in the list.\n";
            }
            break;
        case 9:  // Get Element by Position
            cout << "Enter the position to get the element: ";
            cin >> position;
            try {
                cout << "Element at position " << position << ": " << list.getElementByPosition(position) << "\n";
            } catch (const out_of_range &e) {
                cout << e.what() << endl;
            }
            break;
        case 10:  // Read Element by Position
            cout << "Enter the position to read the element: ";
            cin >> position;
            value = list.ReadElement(position);
            if (value != -1) {
                cout << "Element at position " << position << ": " << value << "\n";
            }
            break;
        case 11:  // Update Element at Position
            cout << "Enter the position to update: ";
            cin >> position;
            cout << "Enter the new value: ";
            cin >> value;
            list.updateElement(position, value);  // Call the updateElement function
            break;
        case 12:  // Display List
            cout << "The elements in the list are:\n";
            list.display();  // Call the display function
            break;
        case 13:  // Traverse List
            cout << "Traversing the list:\n";
            list.traverse();  // Call the traverse function
            break;
        case 14:  // Check if List is Empty
            if (list.isEmpty()) {
                cout << "The list is empty.\n";
            } else {
                cout << "The list is not empty.\n";
            }
            break;
        case 15:  // Exit
            cout << "Exiting...\n";
            return;
        default:  // Invalid choice
            cout << "Invalid choice. Please try again.\n";
    }
}
