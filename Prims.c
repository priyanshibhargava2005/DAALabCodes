#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

// Function to find the vertex with the minimum key value
int minKey(int key[], int sptSet[], int vertices)
{
    int min = INT_MAX, minIndex;

    for (int v = 0; v < vertices; v++)
    {
        if (!sptSet[v] && key[v] < min) // Find the minimum key not yet included in MST
        {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the Minimum Spanning Tree
void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int vertices)
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++)
    {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to implement Prim's algorithm for a given graph
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int vertices)
{
    int key[MAX_VERTICES];    // Array to store the minimum edge weight to connect to MST
    int parent[MAX_VERTICES]; // Array to store the MST structure
    int sptSet[MAX_VERTICES]; // Similar to Dijkstra's, but here it means MST inclusion set

    // Initialize all keys as INFINITE and sptSet[] as false
    for (int i = 0; i < vertices; i++)
    {
        key[i] = INT_MAX; // Initialize all keys to "infinity" (no connection)
        sptSet[i] = 0;    // Mark all vertices as not included in MST
    }

    // Start MST from the first vertex
    key[0] = 0;     // Root vertex has key value 0
    parent[0] = -1; // First node has no parent (starting point of MST)

    // MST will have `vertices - 1` edges
    for (int count = 0; count < vertices - 1; count++)
    {
        // Pick the minimum key vertex not yet included in MST
        int u = minKey(key, sptSet, vertices);
        sptSet[u] = 1; // Mark the picked vertex as included in MST

        // Update key and parent for adjacent vertices of the picked vertex
        for (int v = 0; v < vertices; v++)
        {
            // Update key[v] if there's a smaller edge weight and v is not yet in MST
            if (graph[u][v] && !sptSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;        // Store u as parent of v
                key[v] = graph[u][v]; // Update key[v] to the weight of edge u-v
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph, vertices);
}

int main()
{
    int vertices;

    // Input the number of vertices
    printf("Input the number of vertices: ");
    scanf("%d", &vertices);

    if (vertices <= 0 || vertices > MAX_VERTICES)
    {
        printf("Invalid number of vertices. Exiting...\n");
        return 1;
    }

    int graph[MAX_VERTICES][MAX_VERTICES];

    // Input the adjacency matrix representing the weighted graph
    printf("Input the adjacency matrix for the graph (use 0 for no connection):\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Run Prim's algorithm to find MST
    primMST(graph, vertices);

    return 0;
}
