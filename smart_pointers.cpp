#include <iostream>
#include <memory>
#include <string>

using namespace std;

// A custom diagnostic blueprint to track exactly when memory is created and destroyed
struct Resource {
    string name;
    
    // Constructor (Runs when memory is allocated)
    Resource(string n) : name(n) {
        cout << "   [ALLOCATED] Resource '" << name << "' built in the Heap." << endl;
    }
    
    // Destructor (Runs when memory is bulldozed)
    ~Resource() {
        cout << "   [DESTROYED] Resource '" << name << "' safely erased. Zero leaks!" << endl;
    }
    
    void execute() {
        cout << "   [ACTIVE] Processing: " << name << endl;
    }
};

int main() {
    cout << "=== PHASE 1: THE RAW POINTER (Legacy C++) ===" << endl;
    Resource* rawPtr = new Resource("Legacy Module");
    rawPtr->execute();
    // If you delete this line, the program leaks memory forever.
    delete rawPtr; 


    cout << "\n=== PHASE 2: UNIQUE POINTERS (Modern C++) ===" << endl;
    { // Opening a temporary local scope
        
        // make_unique securely allocates the memory and gives exclusive ownership to 'uniquePtr'
        unique_ptr<Resource> uniquePtr = make_unique<Resource>("Secure Module");
        uniquePtr->execute();
        
        cout << "   -> Exiting local scope..." << endl;
    } // <--- The unique_ptr detects the scope ending and AUTOMATICALLY calls delete here.


    cout << "\n=== PHASE 3: SHARED POINTERS (Reference Counting) ===" << endl;
    {
        // make_shared allows multiple maps to point to the exact same house.
        shared_ptr<Resource> masterPtr = make_shared<Resource>("Shared Module");
        cout << "   -> Active Owners: " << masterPtr.use_count() << endl;
        
        { // Opening an inner scope
            shared_ptr<Resource> temporaryPtr = masterPtr; 
            cout << "   -> Temporary pointer connected. Active Owners: " << masterPtr.use_count() << endl;
        } // temporaryPtr is destroyed here. 
        
        cout << "   -> Temporary pointer died. Active Owners: " << masterPtr.use_count() << endl;
        cout << "   -> Exiting main scope..." << endl;
    } // masterPtr is destroyed here. Active Owners drops to 0. The memory is AUTOMATICALLY bulldozed.

    cout << "\nSystem terminating normally." << endl;
    return 0;
}