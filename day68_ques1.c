#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

// Queue structure for BFS
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Add element to queue
void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

// Remove element from queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        // Queue becomes empty
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

int main() {
    int n, e;  // n = number of vertices, e = number of edges
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    int adj[MAX][MAX] = {0}; // Adjacency matrix
    int indegree[MAX] = {0}; // Array to store in-degree of vertices

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;  // Increment in-degree of v
    }

    Queue q;
    initQueue(&q);

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    printf("Topological Sort Order: ");

    int count = 0; // To check for cycles
    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        printf("%d ", u);
        count++;

        // Decrease in-degree of neighbors
        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(&q, v);
                }
            }
        }
    }

    if (count != n) {
        printf("\nGraph contains a cycle! Topological sort not possible.\n");
    }

    return 0;
}
