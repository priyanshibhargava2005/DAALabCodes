#include <stdio.h>

// Function to perform the Knapsack calculation using the Greedy strategy
void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0; // x[] stores the fractions of items in the knapsack
    int i, j, u;         // u stores the remaining capacity of the knapsack
    u = capacity;

    // Initialize all elements of x[] to 0 (no items are in the knapsack initially)
    for (i = 0; i < n; i++)
        x[i] = 0.0;

    // Greedy approach: Add items until the knapsack is full
    for (i = 0; i < n; i++)
    {
        if (weight[i] > u) // If the item can't fit, break the loop
            break;
        else
        {
            x[i] = 1.0;          // Take the whole item
            tp = tp + profit[i]; // Add the profit of the item to total profit
            u = u - weight[i];   // Reduce the remaining capacity
        }
    }

    // If there's still remaining capacity, take a fraction of the next item
    if (i < n)
        x[i] = u / weight[i]; // Take the fraction that fits

    tp = tp + (x[i] * profit[i]); // Add the profit of the fractional item

    // Display the result
    printf("\nThe result vector is: ");
    for (i = 0; i < n; i++)
        printf("%f\t", x[i]); // Display the fractions of each item in the knapsack

    printf("\nMaximum profit is: %f", tp); // Display the total profit
}

int main()
{
    float weight[20], profit[20], capacity;
    int num, i, j;
    float ratio[20], temp;

    // Input the number of items
    printf("\nEnter the number of objects: ");
    scanf("%d", &num);

    // Input the weights and profits of each item
    printf("\nEnter the weights and profits of each object: ");
    for (i = 0; i < num; i++)
    {
        scanf("%f %f", &weight[i], &profit[i]);
    }

    // Input the capacity of the knapsack
    printf("\nEnter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    // Calculate the value-to-weight ratio for each item
    for (i = 0; i < num; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort items in descending order of their value-to-weight ratio
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    // Call the knapsack function to calculate the maximum profit
    knapsack(num, weight, profit, capacity);
    return 0;
}