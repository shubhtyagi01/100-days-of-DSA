#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list node
struct Node {
    int vertex, weight;
    struct Node* next;
};

// Create new node
struct Node* newNode(int v, int w) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->vertex = v;
    temp->weight = w;
    temp->next = NULL;
    return temp;
}

// Add edge (undirected)
void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* temp = newNode(v, w);
    temp->next = adj[u];
    adj[u] = temp;

    temp = newNode(u, w);
    temp->next = adj[v];
    adj[v] = temp;
}

// Min distance vertex
int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra Algorithm
void dijkstra(struct Node* adj[], int n, int src) {
    int dist[MAX], visited[MAX];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 1; i <= n; i++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
            temp = temp->next;
        }
    }

    // Print result
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[MAX];

    // Initialize adjacency list
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }

    int u, v, w;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }

    int source;
    scanf("%d", &source);

    dijkstra(adj, n, source);

    return 0;
}
