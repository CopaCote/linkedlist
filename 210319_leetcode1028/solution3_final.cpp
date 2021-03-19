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
        size_t index;
        TreeNode *root = new TreeNode(stoi(S, &index)); // root Setting

        stack<TreeNode *> myStack;
        myStack.push(root);

        int currDepth = 0;
        while (index < S.size())
        {
            int nextDepth = 0;
            while (S[index] == '-')
            {
                index++;
                nextDepth++;
            }
            for (int i = 0; i <= currDepth - nextDepth; i++)
                myStack.pop();
            int val = 0;
            while (index < S.size() && S[index] != '-')
            {
                val = val * 10 + (S[index] - '0');
                index++;
            }
            TreeNode *child = new TreeNode(val);
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