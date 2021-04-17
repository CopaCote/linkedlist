/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator
{
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        recc(root);
    }

    void recc(TreeNode *node)
    {
        if (node->right != nullptr)
            recc(node->right);
        st.push(node);
        if (node->left != nullptr)
            recc(node->left);
    }

    int next()
    {
        int val = st.top()->val;
        st.pop();
        return val;
    }

    bool hasNext()
    {
        if (!st.empty())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */