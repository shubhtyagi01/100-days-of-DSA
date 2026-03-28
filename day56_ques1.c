#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to check mirror
int isMirror(Node* t1, Node* t2) {
    if (t1 == NULL && t2 == NULL)
        return 1;

    if (t1 == NULL || t2 == NULL)
        return 0;

    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Function to check symmetric tree
int isSymmetric(Node* root) {
    if (root == NULL)
        return 1;
    return isMirror(root->left, root->right);
}

// Build tree from level order
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;

            if (leftIndex < n)
                nodes[i]->left = nodes[leftIndex];

            if (rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    return nodes[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n);

    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
