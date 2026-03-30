#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build Tree
struct Node* buildTree(int preorder[], int inorder[], int start, int end, int *preIndex) {
    if (start > end)
        return NULL;

    // Pick current node from preorder
    struct Node* root = newNode(preorder[*preIndex]);
    (*preIndex)++;

    // If leaf node
    if (start == end)
        return root;

    // Find index in inorder
    int inIndex = search(inorder, start, end, root->data);

    // Build left and right subtrees
    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// Print Postorder
void printPostorder(struct Node* root) {
    if (root == NULL)
        return;

    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printPostorder(root);

    return 0;
}
