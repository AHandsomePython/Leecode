

int res = 0;
int rank = 0;
void traverse(TreeNode* root, int k) {
    if (root == nullptr) {
        return;
    }
    traverse(root->left, k);
    /* 中序遍历代码位置 */
    rank++;
    if (k == rank) {
        res = root->val;
        return;
    }
    /*****************/
    traverse(root->right, k);
}
