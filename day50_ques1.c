#include <stdio.h>
#include <stdlib.h>

// Define structure for BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Search in BST
int search(struct Node* root, int key) {
    if (root == NULL) {
        return 0; // Not found
    }
    if (root->data == key) {
        return 1; // Found
    } else if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    int n, i, key, value;
    struct Node* root = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input BST elements
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Input key to search
    scanf("%d", &key);

    // Search and print result
    if (search(root, key)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}
