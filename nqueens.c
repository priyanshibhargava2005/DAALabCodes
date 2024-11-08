#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Function to print the chessboard
void printSolution(int board[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[MAX][MAX], int row, int col, int n)
{
    // Check the column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueens(int board[MAX][MAX], int row, int n)
{
    // If all queens are placed
    if (row == n)
    {
        printSolution(board, n);
        return true;
    }

    // Try placing this queen in all columns one by one
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 1; // Place the queen

            // Recur to place the next queen
            if (solveNQueens(board, row + 1, n))
            {
                return true;
            }

            // If placing queen in current column doesn't lead to a solution,
            // backtrack by removing the queen
            board[row][col] = 0;
        }
    }

    // If the queen cannot be placed in any column in this row, return false
    return false;
}

int main()
{
    int n;
    printf("Enter the value of n (for n×n chessboard): ");
    scanf("%d", &n);

    int board[MAX][MAX] = {0}; // Initialize the board with 0s (no queens placed)

    if (!solveNQueens(board, 0, n))
    {
        printf("Solution does not exist for %d queens.\n", n);
    }

    return 0;
}
