#include <stdio.h>

// Function to perform the Knapsack calculation using the Greedy strategy
void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0; // x[] stores the fractions of items in the knapsack
    int i;
    float u = capacity; // u stores the remaining capacity of the knapsack

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
    for (int k = 0; k < n; k++)
        printf("%f\t", x[k]); // Display the fractions of each item in the knapsack

    printf("\nMaximum profit is: %f", tp); // Display the total profit
}

int main()
{
    float weight[20], profit[20], capacity;
    int num, i;
    float temp;

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

    // Sort items in descending order of their value-to-weight ratio
    for (i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (profit[i] / weight[i] < profit[j] / weight[j])
            {
                // Swap profit[i] with profit[j]
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;

                // Swap weight[i] with weight[j]
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
            }
        }
    }

    // Call the knapsack function to calculate the maximum profit
    knapsack(num, weight, profit, capacity);
    return 0;
}
