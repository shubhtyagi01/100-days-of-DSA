#include <stdio.h>

#define MAX 100

typedef struct {
    int x, y;
} Pair;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    Pair queue[MAX];
    int front = 0, rear = 0;

    int fresh = 0;

    // Directions: up, down, left, right
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    // Step 1: Add all rotten oranges to queue & count fresh ones
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (Pair){i, j};
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    // If no fresh oranges
    if (fresh == 0) return 0;

    int minutes = 0;

    // Step 2: BFS
    while (front < rear) {
        int size = rear - front;
        int rottenThisRound = 0;

        for (int i = 0; i < size; i++) {
            Pair curr = queue[front++];

            for (int d = 0; d < 4; d++) {
                int nx = curr.x + dir[d][0];
                int ny = curr.y + dir[d][1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    queue[rear++] = (Pair){nx, ny};
                    fresh--;
                    rottenThisRound = 1;
                }
            }
        }

        if (rottenThisRound) minutes++;
    }

    return (fresh == 0) ? minutes : -1;
}
