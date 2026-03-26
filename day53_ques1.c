#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue node with horizontal distance
struct QNode {
    struct Node* node;
    int hd;
};

// Create new tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = createNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int l = 2*i + 1;
            int r = 2*i + 2;

            if (l < n)
                nodes[i]->left = nodes[l];
            if (r < n)
                nodes[i]->right = nodes[r];
        }
    }

    return nodes[0];
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    // Simple queue
    struct QNode queue[1000];
    int front = 0, rear = 0;

    // Array to store verticals (shifted index)
    int map[2000][100];  // map[hd][values]
    int count[2000] = {0};

    int offset = 1000; // to handle negative HD

    int min_hd = 0, max_hd = 0;

    // Push root
    queue[rear++] = (struct QNode){root, 0};

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        int idx = hd + offset;
        map[idx][count[idx]++] = curr->data;

        if (hd < min_hd) min_hd = hd;
        if (hd > max_hd) max_hd = hd;

        if (curr->left)
            queue[rear++] = (struct QNode){curr->left, hd - 1};
        if (curr->right)
            queue[rear++] = (struct QNode){curr->right, hd + 1};
    }

    // Print result
    for (int i = min_hd; i <= max_hd; i++) {
        int idx = i + offset;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, N);

    verticalOrder(root);

    return 0;
}
