#include <stdio.h>

void quicksort(int a[], int beg, int end)
{
    int i, j, pivot, temp;

    if (beg < end)
    {
        pivot = beg;
        i = beg;
        j = end;

        // Partition the subarray
        while (i < j)
        {
            // Move i to the right until it finds an element greater than the pivot
            while (a[i] <= a[pivot] && i < end)
                i++;

            // Move j to the left until it finds an element smaller than the pivot
            while (a[j] > a[pivot])
                j--;

            // Swap the elements at positions i and j, if i is still less than j
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        // Move the pivot element to its correct position
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;

        // Display the array after each partition
        printf("Array after partition with pivot %d: ", a[j]);
        for (int k = 0; k <= end; k++)
            printf("%d ", a[k]);
        printf("\n");

        // Recursively call quicksort on the left and right subarrays
        quicksort(a, beg, j - 1);
        quicksort(a, j + 1, end);
    }
}

int main()
{
    int i, n, a[25];

    printf("How many elements are you going to enter?: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Call quicksort
    quicksort(a, 0, n - 1);

    printf("Order of Sorted elements: ");
    for (i = 0; i < n; i++)
        printf(" %d", a[i]);

    return 0;
}
