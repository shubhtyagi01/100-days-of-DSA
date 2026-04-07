#include <stdbool.h>
#include <stdlib.h>

bool dfs(int node, int* visited, int* recStack, int** adj, int* adjSize) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, recStack, adj, adjSize))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; 
        }
    }

    recStack[node] = 0; 
    return false;
}


bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {


    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    
    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(prerequisitesSize * sizeof(int));
    }

    
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        adj[b][adjSize[b]++] = a;
    }

    int* visited = (int*)calloc(numCourses, sizeof(int));
    int* recStack = (int*)calloc(numCourses, sizeof(int));

    
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, adj, adjSize))
                return false;
        }
    }

    return true;
}
