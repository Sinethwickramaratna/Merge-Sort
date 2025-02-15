# Merge-Sort
Merge sort is a sorting algorithm that uses divide and conqueror method 
Merge Sort is a divide-and-conquer sorting algorithm that splits an array into smaller subarrays, sorts them, and then merges them back together in a sorted order.

How Merge Sort Works
Divide: The array is recursively divided into two halves until each subarray contains only one element.
Conquer: Each subarray (single elements) is already sorted, so the algorithm merges them back together in sorted order.
Merge: The merging step combines two sorted subarrays into a larger sorted subarray.
Steps in Detail
If the array has one or zero elements, it is already sorted.
Recursively divide the array into two halves until each subarray has only one element.
Merge the subarrays back together by comparing elements and arranging them in sorted order.
Repeat the merging process until the full array is reconstructed.
Example
Let’s sort the array [6, 3, 8, 5, 2, 7, 4, 1] using Merge Sort.

Step 1: Divide
[6, 3, 8, 5]   |   [2, 7, 4, 1]
[6, 3]  [8, 5] | [2, 7]  [4, 1]
[6] [3] [8] [5] | [2] [7] [4] [1]
Each subarray now has only one element.

Step 2: Merge
[3, 6] [5, 8]  | [2, 7] [1, 4]
[3, 5, 6, 8]   | [1, 2, 4, 7]

Step 3: Final Merge
[1, 2, 3, 4, 5, 6, 7, 8]


Now the array is fully sorted.

Time Complexity

Best Case: 𝑂(𝑛log𝑛)
Worst Case: 𝑂(𝑛log𝑛)
Average Case: 𝑂(𝑛log⁡𝑛)

Space Complexity
Requires O(n) extra space for merging.

Key Features

Stable Sort (Preserves order of equal elements)
Efficient for large datasets
