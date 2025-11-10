
#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

// Queue functions
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is FULL!\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Function to remove element
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front++;
    }
}

int isEmpty() {
    return (front == -1 || front > rear);
}

int main() {
    int n, i, j, start_vertex;
    int adj[MAX][MAX];
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter adjacency matrix (%dx%d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start_vertex);

    // BFS Algorithm
    visited[start_vertex] = 1;
    enqueue(start_vertex);

    printf("BFS traversal: ");
    while (!isEmpty()) {
        int vertex = dequeue();
        printf("%d ", vertex);

        for (i = 0; i < n; i++) {
            if (adj[vertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");

    return 0;
}
































