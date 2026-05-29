#include <iostream>
using namespace std;

// 1. The Blueprint (The House)
struct Node {
    int data;
    Node* next;
};

// 2. The Management Office (The System)
class LinkedList {
private:
    // This is the master map sitting on the office desk. 
    // It is strictly protected so no outside code can accidentally overwrite it.
    Node* head;

public:
    // The Constructor: When the office first opens, the city is empty.
    LinkedList() {
        head = nullptr;
    }

    // The Automated Construction Crew
    void insert(int score) {
        // Step 1: Build the new house and pack it with data
        Node* newNode = new Node;
        newNode->data = score;
        newNode->next = nullptr; // It is the newest house, so it points to nowhere

        // Step 2: Check if the city is totally empty
        if (head == nullptr) {
            head = newNode; // Put the first address on the master desk map
            return;         // Job done, exit the function
        }

        // Step 3: The Traversal (Driving to the end of the city)
        Node* current = head; // Start the drive at House 1
        
        while (current->next != nullptr) {
            current = current->next; // Drive to the next house
        }

        // Step 4: We found the last house! Wire the new house to it.
        current->next = newNode;
    }

    // The Reporting Tool
    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = head;
        cout << "Current Linked List: ";
        while (current != nullptr) {
            cout << "[" << current->data << "] -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    cout << "--- AUTOMATED LINKED LIST SYSTEM ---" << endl;

    // Boot up the Management Office
    LinkedList studentMarks;

    // Command the system to build and connect the houses automatically
    studentMarks.insert(85);
    studentMarks.insert(90);
    studentMarks.insert(95);
    studentMarks.insert(100);
    studentMarks.insert(73);

    // Print the final chain
    studentMarks.display();

    return 0;
}