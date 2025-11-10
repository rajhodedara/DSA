#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];    // Adjacency matrix
int visited[MAX];     // Visited array
int n;                // Number of vertices

// Recursive DFS function
void DFS(int v) {
    visited[v] = 1;              // Mark current node as visited
    printf("%d ", v);            // Print the node

    // Visit all adjacent unvisited nodes
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}
int main() {
    int edges, v1, v2, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (v1 v2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);
        adj[v1][v2] = 1;
        adj[v2][v1] = 1;   // Undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);

    return 0;
}


