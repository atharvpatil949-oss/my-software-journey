#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    cout << "=== PHASE 1: C-STRINGS VS C++ STRINGS ===" << endl;
    
    // C-Strings require manual bounds management. If you guess the array size wrong, the program crashes.
    char c_str[20];
    strcpy(c_str, "Legacy C-String"); 
    cout << "Manual C-String: " << c_str << endl;

    // C++ Strings dynamically handle their own memory allocations behind the scenes.
    string cpp_str = "Modern C++ String";
    cpp_str += " (Automated)";
    cout << "Dynamic C++ String: " << cpp_str << endl;


    cout << "\n=== PHASE 2: SMALL STRING OPTIMIZATION (SSO) ===" << endl;
    // To prevent slow Heap allocations, C++ has a secret compartment on the Stack for small strings.
    
    string smallStr = "Short"; 
    string largeStr = "This string is intentionally made incredibly long to completely overwhelm the secret SSO compartment.";

    // The (void*) forces the computer to print the raw hardware address instead of the letters.
    cout << "Hardware Address of smallStr object (Desk/Stack): " << &smallStr << endl;
    cout << "Hardware Address of smallStr data   (Desk/Stack): " << (void*)smallStr.data() << endl;
    cout << "   -> [NOTICE] The addresses are nearly identical. The data is hidden right on the desk!\n" << endl;
    
    cout << "Hardware Address of largeStr object (Desk/Stack): " << &largeStr << endl;
    cout << "Hardware Address of largeStr data   (City/Heap) : " << (void*)largeStr.data() << endl;
    cout << "   -> [NOTICE] A massive jump in addresses. The string was too big, so the OS built it out in the Heap." << endl;


    cout << "\n=== PHASE 3: STRING ITERATOR INVALIDATION ===" << endl;
    // Just like Vectors, Strings can invalidate iterators if they are forced to grow and relocate memory.
    
    string dataStr = "Data";
    string::iterator it = dataStr.begin(); // Map pointing to 'D'
    
    cout << "Initial string data address: " << (void*)dataStr.data() << endl;
    
    // Triggering a massive reallocation
    dataStr.reserve(200); 
    
    cout << "New string data address: " << (void*)dataStr.data() << endl;
    cout << "[CRITICAL] The old 'it' map is pointing to demolished memory. Accessing it causes a crash!" << endl;
    
    // Safety protocol: Always re-assign iterators after memory operations
    it = dataStr.begin();
    cout << "Iterator safely re-routed." << endl;

    return 0;
}