#include <iostream>
#include <vector>
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

    // Insert at end (for testing)
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

    // -------- UTILITIES --------
    void printList() {
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

    int countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    vector<int> toVector() {
        vector<int> vec;
        Node* temp = head;
        while (temp != nullptr) {
            vec.push_back(temp->data);
            temp = temp->next;
        }
        return vec;
    }

    int* toArr(int &size) {
        size = countNodes();
        if (size == 0) return nullptr;

        int* arr = new int[size];
        Node* temp = head;
        int i = 0;
        while (temp != nullptr) {
            arr[i++] = temp->data;
            temp = temp->next;
        }
        return arr;
    }
};

// -------- MAIN --------
int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    // printList()
    list.printList(); // 10 -> 20 -> 30 -> 40 -> NULL

    // countNodes()
    cout << "Total nodes: " << list.countNodes() << endl;

    // toVector()
    vector<int> vec = list.toVector();
    cout << "Vector elements: ";
    for (int v : vec) cout << v << " ";
    cout << endl;

    // toArr()
    int size;
    int* arr = list.toArr(size);
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    delete[] arr; // Free array memory

    return 0;
}
