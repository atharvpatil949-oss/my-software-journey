#include <iostream>
#include <vector>
#include <algorithm> // Required for sort, reverse, and find
#include <numeric>   // Required for math operations like accumulate

using namespace std;

void printVector(const vector<int>& v) {
    for(int score : v) cout << score << " ";
    cout << endl;
}

int main() {
    // We initialize a vector with unsorted student marks
    vector<int> marks = {73, 85, 45, 92, 100, 56};
    
    cout << "=== PHASE 1: HARDWARE SORTING ===" << endl;
    cout << "Original Data: ";
    printVector(marks);

    // std::sort uses an IntroSort algorithm (QuickSort + HeapSort) under the hood.
    // It requires two iterators: where to start, and where to stop.
    sort(marks.begin(), marks.end());
    cout << "Sorted Ascending: ";
    printVector(marks);

    // std::reverse physically flips the memory layout
    reverse(marks.begin(), marks.end());
    cout << "Sorted Descending: ";
    printVector(marks);


    cout << "\n=== PHASE 2: MEMORY SEARCHING ===" << endl;
    int target = 92;
    
    // std::find scans the memory block for a specific value.
    // It returns an iterator (a map) pointing to the exact memory address if found.
    vector<int>::iterator it = find(marks.begin(), marks.end(), target);

    if (it != marks.end()) {
        // We use std::distance to calculate exactly how many bytes/houses 
        // exist between the start of the vector and our target.
        int index = distance(marks.begin(), it);
        cout << "Target " << target << " found at memory index: " << index << endl;
    } else {
        cout << "Target " << target << " does not exist in this memory block." << endl;
    }


    cout << "\n=== PHASE 3: AGGREGATION (std::accumulate) ===" << endl;
    // std::accumulate adds all values in the range. 
    // The '0' at the end is the starting integer value for the sum.
    int sum = accumulate(marks.begin(), marks.end(), 0);
    double average = static_cast<double>(sum) / marks.size();

    cout << "Total Sum of Marks: " << sum << endl;
    cout << "Class Average: " << average << endl;

    return 0;
}