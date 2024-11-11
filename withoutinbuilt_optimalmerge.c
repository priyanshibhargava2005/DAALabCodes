#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to implement the min-heap data structure
void minHeapify(int heap[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
    {
        smallest = left;
    }

    if (right < n && heap[right] < heap[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        // Swap the values
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        // Recursively heapify the affected subtree
        minHeapify(heap, n, smallest);
    }
}

// Function to build a min-heap from the given array
void buildMinHeap(int heap[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minHeapify(heap, n, i);
    }
}

// Function to perform the optimal merge pattern (minimizing merge cost)
int optimalMergePattern(int arr[], int n)
{
    int totalCost = 0;

    // Build a min-heap from the array
    buildMinHeap(arr, n);

    // Continue merging until only one file remains
    while (n > 1)
    {
        // Extract the two smallest elements
        int first = arr[0];
        arr[0] = arr[n - 1];
        n--;
        minHeapify(arr, n, 0);

        int second = arr[0];
        arr[0] = arr[n - 1];
        n--;
        minHeapify(arr, n, 0);

        // Merge the two files
        int mergeCost = first + second;
        totalCost += mergeCost;

        // Insert the merged file back into the heap
        arr[n] = mergeCost;
        n++;
        minHeapify(arr, n, 0);
    }

    return totalCost;
}

int main()
{
    int n;
    printf("Enter the number of files: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of files. Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];
    printf("Enter the sizes of the files: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Compute and print the total minimum cost for the optimal merge
    int minCost = optimalMergePattern(arr, n);
    printf("The total minimum cost of merging the files is: %d\n", minCost);

    return 0;
}
