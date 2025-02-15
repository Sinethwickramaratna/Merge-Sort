#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted subarrays into one sorted subarray
vector<int> merge(vector<int> arr, int L1, int R1, int L2, int R2) {
    vector<int> temp; // Temporary vector to store the merged result
    
    // Merge the two subarrays while both have elements
    while (L1 <= R1 && L2 <= R2) {
        if (arr[L1] <= arr[L2]) { 
            temp.push_back(arr[L1]); 
            L1++; 
        } else { 
            temp.push_back(arr[L2]); 
            L2++; 
        }
    }
    
    // Copy remaining elements from first subarray (if any)
    while (L1 <= R1) {
        temp.push_back(arr[L1]);
        L1++;
    }

    // Copy remaining elements from second subarray (if any)
    while (L2 <= R2) {
        temp.push_back(arr[L2]);
        L2++;
    }
    
    return temp; // Return the merged sorted array
}

// Function to perform iterative (bottom-up) merge sort
vector<int> iterativeMergeSort(vector<int> arr) {
    int n = arr.size(); // Get the array size
    int len = 1;  // Initial subarray size (single elements)
    
    while (len < n) { // Continue merging until the entire array is sorted
        int i = 0;
        
        while (i < n) {
            int L1 = i;
            int R1 = i + len - 1;
            int L2 = i + len;
            int R2 = i + 2 * len - 1;
            
            // Ensure we don't go out of bounds
            if (L2 >= n) break; // If second subarray starts out of bounds, stop
            
            if (R2 >= n) R2 = n - 1; // Adjust last index to fit within bounds
            
            // Merge the two subarrays and store the result
            vector<int> temp = merge(arr, L1, R1, L2, R2);
            
            // Copy merged elements back into the original array
            for (int j = 0; j < R2 - L1 + 1; j++) {
                arr[i + j] = temp[j];
            }

            // Move to the next pair of subarrays
            i = i + 2 * len;
        }
        
        len = 2 * len; // Double the subarray size for the next iteration
    }
    
    return arr; // Return the sorted array
}

int main() {
    vector<int> arr = {2, 4, 5, 1, 7, 6, 3}; // Example array
    
    // Output the sorted array
    for (int i : iterativeMergeSort(arr)) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
