

// 前序遍历 preorder[preStart..preEnd]，中序遍历 inorder[inStart..inEnd] 构造二叉树
TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 
                vector<int>& inorder, int inStart, int inEnd) {
    // 前序位置，寻找左右子树的索引
    if (preStart > preEnd) {
        return nullptr;
    }
    int rootVal = preorder[preStart];
    int index = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootVal) {
            index = i;
            break;
        }
    }
    int leftSize = index - inStart;
    TreeNode* root = new TreeNode(rootVal);

    // 递归构造左右子树
    root->left = build(preorder, preStart + 1, preStart + leftSize,
                      inorder, inStart, index - 1);
    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                       inorder, index + 1, inEnd);
    return root;
}
