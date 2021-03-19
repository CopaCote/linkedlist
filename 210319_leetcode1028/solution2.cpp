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
class Solution
{
public:
    TreeNode *recoverFromPreorder(string S)
    {
        size_t p;
        TreeNode *root = new TreeNode(stoi(S, &p)); // root Setting
        S = S.substr(p);                            // Cut the front Part

        stack<TreeNode *> myStack;
        myStack.push(root);

        int currDepth = 0;
        while (S != string())
        {
            int nextDepth = 0;
            p = 0;
            while (S[nextDepth] == '-')
                nextDepth++;
            for (int i = 0; i <= currDepth - nextDepth; i++)
                myStack.pop();
            S = S.substr(nextDepth);
            TreeNode *child = new TreeNode(stoi(S, &p));
            S = S.substr(p);
            addChild(myStack.top(), child);
            myStack.push(child);
            currDepth = nextDepth;
        }
        return root;
    }

    void addChild(TreeNode *parent, TreeNode *child)
    {
        if (parent->left == nullptr)
            parent->left = child;
        else
            parent->right = child;
    }
};