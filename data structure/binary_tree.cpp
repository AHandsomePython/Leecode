/* 基本的二叉树节点 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

void traverse(TreeNode* root) {
    // 前
    traverse(root->left);
    // 中
    traverse(root->right);
    // 后
}


// M-L-R

vector<int> res;

// 返回前序遍历结果
vector<int> preorder(TreeNode* root) {
    traverse(root);
    return res;
}

// 二叉树遍历函数
void traverse(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // 前序遍历位置
    res.push_back(root->val);
    traverse(root->left);
    traverse(root->right);
}



// 定义：输入一棵二叉树的根节点，返回这棵树的前序遍历结果
vector<int> preorder(TreeNode* root) {
    vector<int> res;
    if (root == NULL) {
        return res;
    }
    // 前序遍历的结果，root->val 在第一个
    res.push_back(root->val);
    // 后面接着左子树的前序遍历结果
    vector<int> left = preorder(root->left);
    // 最后接着右子树的前序遍历结果
    vector<int> right = preorder(root->right);
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    return res;
}
