#include <stdio.h>

#define MAX 100

int visited[MAX];

// Recursive DFS function
void dfs(int adj[MAX][MAX], int n, int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(adj, n, i);
        }
    }
}

int main() {
    int n, s;
    int adj[MAX][MAX];

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Input starting vertex
    printf("Enter starting vertex: ");
    scanf("%d", &s);

    // Perform DFS
    printf("DFS traversal: ");
    dfs(adj, n, s);

    return 0;
}
