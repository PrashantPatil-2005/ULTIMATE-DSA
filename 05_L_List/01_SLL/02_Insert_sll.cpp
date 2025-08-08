#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor 1: set data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor 2: set data, next = nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head = nullptr;
    
    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value, head);
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at specific position (1-based)
    void insertAtPosition(int value, int position) {
    Node* newNode = new Node(value);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
    // Display linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    // Insert at beginning
    list.insertAtBeginning(10);
    list.insertAtBeginning(5);
    list.display(); // 5 -> 10 -> NULL

    // Insert at end
    list.insertAtEnd(20);
    list.insertAtEnd(25);
    list.display(); // 5 -> 10 -> 20 -> 25 -> NULL

    // Insert at position
    list.insertAtPosition(15, 3);
    list.display(); // 5 -> 10 -> 15 -> 20 -> 25 -> NULL

    list.insertAtPosition(100, 1);
    list.display(); // 100 -> 5 -> 10 -> 15 -> 20 -> 25 -> NULL

    list.insertAtPosition(50, 10); // Invalid
    list.display();

    return 0;
}
