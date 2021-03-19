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
        addChild(root, 0, S);

        return root;
    }

    string addChild(TreeNode *parent, int depth, string S)
    {
        int d = 0;
        size_t p = 0;
        while (S[d] == '-')
            d++;
        if (d > depth)
        {
            S = S.substr(d);
            parent->left = new TreeNode(stoi(S, &p));
            S = S.substr(p);
            S = addChild(parent->left, depth + 1, S);
        }
        else
            return S;

        d = 0;
        while (S[d] == '-')
            d++;
        if (d > depth)
        {
            S = S.substr(d);
            parent->right = new TreeNode(stoi(S, &p));
            S = S.substr(p);
            S = addChild(parent->right, depth + 1, S);
        }
        else
            return S;
        return S;
    }
};