#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Function to create circular doubly linked list from user input
void createList(int n) {
    Node* temp;
    Node* newNode;
    int value;

    for (int i = 0; i < n; i++) {
        cout << "Enter mark " << i + 1 << ": ";
        cin >> value;

        newNode = new Node;
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            temp = head->prev; // last node
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
        }
    }
}

// Add at beginning
void addAtBeginning(int value) {
    Node* newNode = new Node;
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

// Add after node with value 45
void addAfterValue(int value, int newValue) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    do {
        if (temp->data == value) {
            Node* newNode = new Node;
            newNode->data = newValue;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value " << value << " not found!\n";
}

// Delete at beginning
void deleteAtBeginning() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* last = head->prev;
    Node* temp = head;
    head = head->next;
    head->prev = last;
    last->next = head;
    delete temp;
}

// Delete node after value 45
void deleteAfterValue(int value) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    do {
        if (temp->data == value) {
            Node* delNode = temp->next;

            if (delNode == head) { // if next is head
                cout << "No node exists after value " << value << "\n";
                return;
            }

            temp->next = delNode->next;
            delNode->next->prev = temp;

            delete delNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "No node exists after value " << value << "\n";
}

// Display list
void display() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    cout << "List: ";
    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)\n";
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    createList(n);
    display();

    cout << "\nAdding 100 at beginning...\n";
    addAtBeginning(100);
    display();

    cout << "\nAdding 200 after 45...\n";
    addAfterValue(45, 200);
    display();

    cout << "\nDeleting at beginning...\n";
    deleteAtBeginning();
    display();

    cout << "\nDeleting node after 45...\n";
    deleteAfterValue(45);
    display();

    return 0;
}
