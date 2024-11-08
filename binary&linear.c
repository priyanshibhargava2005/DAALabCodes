#include <stdio.h>

// Linear Search (Recursive)
int linearSearch(int arr[], int n, int key)
{
    if (n == 0)
        return -1; // Element not found
    if (arr[n - 1] == key)
        return n - 1;                     // Element found
    return linearSearch(arr, n - 1, key); // Recur for the rest of the array
}

// Binary Search (Recursive)
int binarySearch(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1; // Element not found

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid; // Element found at mid
    else if (arr[mid] > key)
        return binarySearch(arr, low, mid - 1, key); // Search in the left half
    else
        return binarySearch(arr, mid + 1, high, key); // Search in the right half
}

int main()
{
    int arr[] = {12, 31, 25, 8, 32, 17, 40, 42};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 32;

    // Linear Search
    int linearResult = linearSearch(arr, n, key);
    if (linearResult != -1)
        printf("Linear Search: Element %d found at index %d\n", key, linearResult);
    else
        printf("Linear Search: Element %d not found\n", key);

    // Binary Search
    // First, sort the array for binary search to work
    int sortedArr[] = {8, 12, 17, 25, 31, 32, 40, 42};
    int binaryResult = binarySearch(sortedArr, 0, n - 1, key);
    if (binaryResult != -1)
        printf("Binary Search: Element %d found at index %d\n", key, binaryResult);
    else
        printf("Binary Search: Element %d not found\n", key);

    return 0;
}
