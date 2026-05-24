#include <iostream>
using namespace std;

int main() {
    //1. Allocate an initial array of size 3 on the Heap
    //Notice the brackets [].We are asking for a block of 3 integers.
    int* arr = new int[3];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    cout << "--- ORIGINAL HEAP ARRAY ---" << endl;
    for(int i = 0; i < 3; i++) cout  << arr[i] << " ";
    cout << "\nOld Hardware Address: " << arr << endl;

    // --- THE CRISIS ---
    // We need to add the number 40, but our block of memory is full.
    // We cannot expand 'arr'. We must build a new one.

    //2. Allocate a NEW, larger array (size 4) on the Heap
    int* temp = new int[4];

    //3. Copy the old data into the new array
    for(int i = 0; i < 3; i++) {
        temp[i] = arr[i];
    }

    // 4. Insert the new data
    temp[3] = 40;
    

    //5. DESTROY the old array to prevent a massive memory leak.
    // Because it is an array, we MUST use delete[] instead of just delete.
    delete[] arr;

    // 6. The Magic Trick: Re-point the original map to the new house
    arr = temp;

    // Neutralize the temporary pointer so it doesn't accidentally mess with our data.
    temp = nullptr;

    cout << "\n--- RESIZED HEAP ARRAY ---" << endl;
    for(int i = 0; i < 4; i++) cout << arr[i] << " ";
    cout << "\nNew Hardware Address: " << arr << endl;

    // 7. Clean up the final array before the program shuts down
    delete[] arr;
    return 0;
}