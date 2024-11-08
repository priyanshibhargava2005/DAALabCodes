#include <stdlib.h>
#include <stdio.h>

// Structure that denotes a weighted edge
struct Edge {
    int source, destination, weight;
};

// Structure that denotes a weighted, undirected, and connected graph
struct Graph {
    int Node, E;
    struct Edge* edge;
};

// Allocates memory for storing graph with V vertices and E edges
struct Graph* GenerateGraph(int Node, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->Node = Node;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge)); // Corrected allocation size
    return graph;
}

// Subset for Union-Find
struct tree_maintainance_set {
    int parent;
    int rank;
};

// Finds the set of chosen element i using path compression
int find_DisjointSet(struct tree_maintainance_set subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find_DisjointSet(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Creates the Union of two sets
void Union_DisjointSet(struct tree_maintainance_set subsets[], int x, int y) {
    int xroot = find_DisjointSet(subsets, x);
    int yroot = find_DisjointSet(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to compare edges using qsort() in C programming
int myComp(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight - b1->weight;  // Simpler comparison
}

// Function to construct MST using Kruskal’s approach
void KruskalMST(struct Graph* graph) {
    int Node = graph->Node;
    struct Edge result[Node]; 
    int e = 0, i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    struct tree_maintainance_set subsets[Node];  // Static array for subsets

    for (int v = 0; v < Node; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < Node - 1 && i < graph->E) {
        struct Edge next_edge = graph->edge[i++];

        int x = find_DisjointSet(subsets, next_edge.source);
        int y = find_DisjointSet(subsets, next_edge.destination);

        if (x != y) {
            result[e++] = next_edge;
            Union_DisjointSet(subsets, x, y);
        }
    }

    printf("Edges created in MST are as below: \n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].source, result[i].destination, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("The Cost for created MST is : %d\n", minimumCost);
}

int main() {
    int Node = 4;
    int E = 6;
    struct Graph* graph = GenerateGraph(Node, E);

    graph->edge[0].source = 0;
    graph->edge[0].destination = 1;
    graph->edge[0].weight = 2;

    graph->edge[1].source = 0;
    graph->edge[1].destination = 2;
    graph->edge[1].weight = 4;

    graph->edge[2].source = 0;
    graph->edge[2].destination = 3;
    graph->edge[2].weight = 4;

    graph->edge[3].source = 1;
    graph->edge[3].destination = 3;
    graph->edge[3].weight = 3;

    graph->edge[4].source = 2;
    graph->edge[4].destination = 3;
    graph->edge[4].weight = 1;

    graph->edge[5].source = 1;
    graph->edge[5].destination = 2;
    graph->edge[5].weight = 2;

    KruskalMST(graph);

    return 0;
}