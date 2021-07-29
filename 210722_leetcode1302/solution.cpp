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
    int deepestLeavesSum(TreeNode *root)
    {
        vector<pair<int, int>> leaves;
        int total = 0;

        dfs(root, leaves, 0);
        sort(leaves.begin(), leaves.end(), greater<>());

        total += leaves[0].second;
        for (int i = 1; i < leaves.size(); i++)
        {
            if (leaves[i].first < leaves[i - 1].first)
                break;
            total += leaves[i].second;
        }

        return total;
    }

    void dfs(TreeNode *node, vector<pair<int, int>> &leaves, int depth)
    {
        int total = 0;

        if (node->left == nullptr && node->right == nullptr)
        {
            leaves.push_back(make_pair(depth, node->val));
            return;
        }

        if (node->left != nullptr)
            dfs(node->left, leaves, depth + 1);
        if (node->right != nullptr)
            dfs(node->right, leaves, depth + 1);
    }
};