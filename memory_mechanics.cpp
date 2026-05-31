#include <iostream>
#include <vector>
#include <string>

using namespace std;

// A custom blueprint to prove how memory is constructed behind the scenes
struct Student {
    string name;
    int score;
    
    // Standard Constructor
    Student(string n, int s) : name(n), score(s) {
        cout << "   -> Constructed: " << name << " in the Heap." << endl;
    }
    
    // Copy Constructor (Triggers when the system is forced to make a duplicate)
    Student(const Student& other) : name(other.name), score(other.score) {
        cout << "   -> [WARNING] Copied: " << name << " to a new location!" << endl;
    }
};

int main() {
    cout << "=== PHASE 1: RESERVE VS RESIZE ===" << endl;
    vector<int> dataMap;
    
    // Reserve ONLY buys the land (allocates capacity), but builds no houses (size remains 0).
    dataMap.reserve(5);
    cout << "After reserve(5) -> Size (Houses): " << dataMap.size() 
         << " | Capacity (Land): " << dataMap.capacity() << endl;

    // Resize actually builds the houses and fills them with default data (0).
    dataMap.resize(3);
    cout << "After resize(3)  -> Size (Houses): " << dataMap.size() 
         << " | Capacity (Land): " << dataMap.capacity() << endl;


    cout << "\n=== PHASE 2: PUSH_BACK VS EMPLACE_BACK ===" << endl;
    vector<Student> roster;
    roster.reserve(2); // Securing land early so the vector doesn't resize and skew our test.

    cout << "Executing push_back(\"Alice\", 90):" << endl;
    // push_back forces the computer to build a temporary Alice, copy her into the vector, and destroy the temp.
    roster.push_back(Student("Alice", 90)); 

    cout << "\nExecuting emplace_back(\"Bob\", 85):" << endl;
    // emplace_back takes the raw materials ("Bob", 85) and builds him DIRECTLY inside the vector's memory. No copies!
    roster.emplace_back("Bob", 85);


    cout << "\n=== PHASE 3: ITERATOR INVALIDATION ===" << endl;
    vector<int> numbers = {10, 20, 30};
    
    // We create a map (iterator) pointing to the first house
    vector<int>::iterator it = numbers.begin();
    cout << "Iterator currently points to: " << *it << endl;
    cout << "Hardware Address of vector: " << numbers.data() << endl;

    cout << "\nTriggering a massive memory reallocation..." << endl;
    // We force the vector to grow past its capacity. 
    // The OS destroys the old array and builds a new one somewhere else.
    numbers.reserve(100); 

    cout << "New Hardware Address of vector: " << numbers.data() << endl;
    cout << "[CRITICAL] The old 'it' map is now pointing to a demolished house (Dead Memory)!" << endl;
    
    // If you typed `cout << *it;` right now, the program would crash (Segmentation Fault).
    // You MUST re-orient your iterators after memory shifts.
    it = numbers.begin();
    cout << "Iterator successfully re-routed. Now safely points to: " << *it << endl;

    
    return 0;
}