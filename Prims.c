// Library to access INT_MAX variable
#include <limits.h>

// Library to create set
#include <stdbool.h>
#include <stdio.h>

#define Vertices 5

// A utility function for finding the vertex with the lowest key value
// from a set of vertices that isn't included in MST.
int Least_Key(int key[], bool Min_Span_Tree[])
{
    int least = INT_MAX, min_index;

    for (int v = 0; v < Vertices; v++)
    {
        if (Min_Span_Tree[v] == false && key[v] < least)
        {
            least = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print created MST
int print_Prims_MST(int parent[], int graph[Vertices][Vertices])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < Vertices; i++)
    {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to generate MST
void prims_MST(int graph[Vertices][Vertices])
{
    int parent[Vertices];
    int key[Vertices];
    bool Min_Span_Tree[Vertices];

    // Initialize all keys as INFINITY and MST[] as false
    for (int i = 0; i < Vertices; i++)
    {
        key[i] = INT_MAX;
        Min_Span_Tree[i] = false;
    }

    key[0] = 0;     // First vertex is always the root of MST
    parent[0] = -1; // First node has no parent

    // The MST will have Vertices - 1 edges
    for (int count = 0; count < Vertices - 1; count++)
    {
        // Pick the minimum key vertex from the set of vertices not yet processed
        int u = Least_Key(key, Min_Span_Tree);
        Min_Span_Tree[u] = true;

        // Update the key and parent for the adjacent vertices of the picked vertex
        for (int v = 0; v < Vertices; v++)
        {
            if (graph[u][v] && Min_Span_Tree[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the created MST
    printf("Created Spanning Tree for Given Graph is: \n\n");
    print_Prims_MST(parent, graph);
}

int main()
{
    // Input graph (Adjacency matrix representation)
    int graph[Vertices][Vertices] = {
        {0, 3, 0, 6, 0},
        {3, 0, 4, 8, 5},
        {0, 4, 0, 0, 7},
        {6, 8, 0, 0, 11},
        {0, 5, 7, 11, 0}};

    // Generate and print the Minimum Spanning Tree (MST)
    prims_MST(graph);

    return 0;
}
