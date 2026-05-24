#include <iostream>
using namespace std;

// We are defining a custom blueprint for a "House" in our fragmented memory city.
struct Node {
    int data;       // Compartment 1: The Payload (e.g., a test score)
    Node* next;     // Compartment 2: The Pointer to the next Node
};

int main() {
    cout << "--- LINKED LIST INITIALIZATION ---" << endl;

    // 1. We ask the OS for a single, isolated Node on the Heap
    Node* head = new Node;

    // 2. We fill the compartments using the arrow operator (->)
    // The arrow is the C++ shortcut for (*head).data
    head->data = 85;
    head->next = nullptr; // This is the only house right now, so the map points to nowhere.

    cout << "Data in the first node: " << head->data << endl;
    cout << "Address of the next node: " << head->next << endl;

    // Clean up
    delete head;
    head = nullptr;

    return 0;
}