#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to count leaf nodes
int countLeafNodes(Node* root) {
    if (root == NULL)
        return 0;

    // If both children are NULL → leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    Node* nodes[n];

    // Create nodes
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(0);
    }

    int value, left, right;

    // Read input and link nodes
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &value, &left, &right);
        nodes[i]->value = value;

        if (left != -1)
            nodes[i]->left = nodes[left];

        if (right != -1)
            nodes[i]->right = nodes[right];
    }

    Node* root = nodes[0];

    int leafCount = countLeafNodes(root);
    printf("%d\n", leafCount);

    return 0;
}
