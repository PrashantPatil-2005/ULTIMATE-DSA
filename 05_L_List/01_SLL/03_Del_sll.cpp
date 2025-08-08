#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // -------- Insert for testing --------
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

    // -------- DELETE OPERATIONS --------
    void deleteHead() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteTail() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int position) {
        if (position < 1 || head == nullptr) {
            cout << "Invalid position or empty list\n";
            return;
        }
        if (position == 1) {
            deleteHead();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of range\n";
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (head->data == value) {
            deleteHead();
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Value not found\n";
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    void deleteEntireList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
    }

    // -------- DISPLAY --------
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

// -------- MAIN --------
int main() {
    LinkedList list;

    // Insert for testing
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.display(); // 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    // Test delete functions
    list.deleteHead();
    list.display(); // 20 -> 30 -> 40 -> 50 -> NULL

    list.deleteTail();
    list.display(); // 20 -> 30 -> 40 -> NULL

    list.deleteAtPosition(2);
    list.display(); // 20 -> 40 -> NULL

    list.deleteByValue(40);
    list.display(); // 20 -> NULL

    list.deleteEntireList();
    list.display(); // List is empty

    return 0;
}
