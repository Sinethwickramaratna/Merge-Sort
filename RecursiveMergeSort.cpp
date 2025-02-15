#include <iostream>
#include <vector>

using namespace std;

// Function to merge two sorted subarrays into a single sorted array
vector<int> merge(vector<int> leftArr, vector<int> rightArr) {
    int n1 = leftArr.size();
    int n2 = rightArr.size();
    vector<int> mergedArr; // Resultant merged array
    
    int i = 0, j = 0;
    
    // Merge elements from leftArr and rightArr in sorted order
    while (i < n1 && j < n2) {
        if (leftArr[i] < rightArr[j]) {
            mergedArr.push_back(leftArr[i]);
            i++;
        } else {
            mergedArr.push_back(rightArr[j]);
            j++;
        }
    }
    
    // Copy remaining elements from leftArr (if any)
    while (i < n1) {
        mergedArr.push_back(leftArr[i]);
        i++;
    }
    
    // Copy remaining elements from rightArr (if any)
    while (j < n2) {
        mergedArr.push_back(rightArr[j]);
        j++;
    }
    
    return mergedArr; // Return the merged sorted array
}

// Function to perform recursive merge sort
vector<int> mergeSort(vector<int> arr) {
    int size = arr.size();
    
    // Base case: if array has one or zero elements, it's already sorted
    if (size <= 1) {
        return arr;
    }

    // Find the middle index of the array
    int mid = size / 2;

    // Split the array into two halves: left and right
    vector<int> leftArr(arr.begin(), arr.begin() + mid);
    vector<int> rightArr(arr.begin() + mid, arr.end());

    // Recursively sort both halves
    leftArr = mergeSort(leftArr);
    rightArr = mergeSort(rightArr);

    // Merge the sorted halves and return the final sorted array
    return merge(leftArr, rightArr);
}

int main() {
    // Sample input array
    vector<int> arr = {40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // Sort the array using mergeSort
    vector<int> sortedArr = mergeSort(arr);

    // Output the sorted array
    for (int i : sortedArr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
