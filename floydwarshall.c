#include <stdio.h>
#include <stdlib.h>

#define V 4       // Number of vertices in the graph
#define INF 99999 // A large value to represent infinity

void floydWarshall(int graph[V][V])
{
    // dist[][] will hold the shortest distance between every pair of vertices
    int dist[V][V];

    // Initialize the distance matrix as the input graph
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // If the path through vertex k is shorter, update the distance
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Display the shortest distance matrix
    printf("Shortest distance matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
            {
                printf("INF\t");
            }
            else
            {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    // Adjacency matrix representation of the graph
    // INF (99999) means no edge between the vertices
    int graph[V][V] = {
        {0, 3, INF, INF},
        {3, 0, 1, INF},
        {INF, 1, 0, 7},
        {INF, INF, 7, 0}};

    // Call the Floyd-Warshall algorithm
    floydWarshall(graph);

    return 0;
}