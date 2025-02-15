**Merge Sort: An Overview**

Merge sort is a sorting algorithm that employs the divide-and-conquer method. It splits an array into smaller subarrays, sorts each one, and then merges them back together in sorted order.

**How Merge Sort Works**

1. **Divide**: The array is recursively divided into two halves until each subarray contains only a single element.
2. **Conquer**: Each subarray (which consists of single elements) is inherently sorted, so the algorithm proceeds to merge them back together in sorted order.
3. **Merge**: The merging step combines two sorted subarrays into a larger sorted subarray.

**Detailed Steps**

- If the array has one or zero elements, it is already sorted.
- Recursively divide the array into two halves until each subarray contains only one element.
- Merge the subarrays back together by comparing their elements and arranging them in sorted order.
- Repeat the merging process until the entire array is reconstructed.

**Example**

Let’s sort the array [6, 3, 8, 5, 2, 7, 4, 1] using merge sort.

**Step 1: Divide**
- [6, 3, 8, 5] | [2, 7, 4, 1]
- [6, 3] | [8, 5] | [2, 7] | [4, 1]
- [6] | [3] | [8] | [5] | [2] | [7] | [4] | [1]

Each subarray now consists of only one element.

**Step 2: Merge**
- Merge [3, 6] | [5, 8] | [2, 7] | [1, 4]
- Resulting in [3, 5, 6, 8] | [1, 2, 4, 7]

**Step 3: Final Merge**
- Combine these to get [1, 2, 3, 4, 5, 6, 7, 8]

Now the array is fully sorted.

**Time Complexity**
- Best Case: O(n log n)
- Worst Case: O(n log n)
- Average Case: O(n log n)

**Space Complexity**
- Requires O(n) extra space for merging.

**Key Features**
- Stable Sort: Preserves the order of equal elements.
- Efficient for large datasets.
