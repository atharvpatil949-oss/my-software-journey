#include <iostream>
using namespace std;

// The Blueprint
struct Node {
    int data;       
    Node* next;     
};

int main() {
    cout << "--- MANUAL LINKED LIST ARCHITECTURE ---" << endl;

    // 1. ALLOCATION (Building the houses in the city)
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;

    // 2. THE PAYLOADS (Putting the test scores inside)
    head->data = 85;
    second->data = 90;
    third->data = 95;

    // 3. THE WIRING (Connecting the internal maps)
    // We walk into the first house and write the second house's address on the counter.
    head->next = second; 
    
    // We walk into the second house and write the third house's address on the counter.
    second->next = third; 
    
    // We walk into the third house and write 'nullptr' because there are no more houses.
    third->next = nullptr; 

    // 4. TRAVERSAL (Proving the chain works)
    cout << "\nAccessing data through the chain:" << endl;
    
    // Reading House 1 directly from our desk
    cout << "Node 1: " << head->data << endl;
    
    // Using House 1's map to find House 2
    cout << "Node 2: " << head->next->data << endl;
    
    // Using House 1's map to find House 2, then using House 2's map to find House 3!
    cout << "Node 3: " << head->next->next->data << endl;

    // 5. DEMOLITION (Preventing memory leaks)
    // We must destroy them one by one.
    delete head;
    delete second;
    delete third;

    // Neutralize the pointers on our desk
    head = nullptr;
    second = nullptr;
    third = nullptr;

    return 0;
}