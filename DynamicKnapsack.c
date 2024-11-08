#include <stdio.h>

// Function to return the maximum of two integers
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// Function to solve the 0/1 Knapsack problem using Dynamic Programming
int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1]; // K[][] table to store maximum values

    // Build the K[][] table in a bottom-up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0; // Base case: no items or zero capacity
            else if (wt[i - 1] <= w)
                // Take the maximum of including the item or excluding it
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w]; // Item cannot be included due to weight
        }
    }

    return K[n][W]; // The bottom-right cell contains the maximum profit
}

int main()
{
    int val[] = {60, 100, 120};           // Profits of items
    int wt[] = {10, 20, 30};              // Weights of items
    int W = 50;                           // Capacity of knapsack
    int n = sizeof(val) / sizeof(val[0]); // Number of items

    printf("\nMaximum value in Knapsack = %d", knapsack(W, wt, val, n)); // Print the maximum profit
    return 0;
}