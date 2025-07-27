class Node {
public:
    int data;
    Node* next;

    // Constructor 1: allows setting both data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor 2: sets next as nullptr by default
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


//20->10->NULL
Node* a = new Node(10);                    // only data
Node* b = new Node(20, a);                 // data and next
