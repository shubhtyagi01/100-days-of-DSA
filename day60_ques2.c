/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int cameras = 0;

// 0 = Not Covered
// 1 = Has Camera
// 2 = Covered
int dfs(struct TreeNode* root) {
    if (root == NULL)
        return 2;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 0 || right == 0) {
        cameras++;
        return 1;
    }

    if (left == 1 || right == 1) {
        return 2;
    }

    return 0;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;

    if (dfs(root) == 0)
        cameras++;

    return cameras;
}
