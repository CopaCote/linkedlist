/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        // if(original != nullptr)
        //     cloned = new TreeNode(original->val);
        //dfs(original, cloned);

        return searchTarget(original, cloned, target);
    }
    // void dfs(TreeNode* node, TreeNode* copy){
    //     if(node->left != nullptr){
    //         copy->left = new TreeNode(node->left->val);
    //         dfs(node->left, copy->left);
    //     }
    //     if(node->right != nullptr){
    //         copy->right = new TreeNode(node->right->val);
    //         dfs(node->right, copy->right);
    //     }
    // }
    TreeNode *searchTarget(TreeNode *node, TreeNode *copy, TreeNode *target)
    {
        TreeNode *temp = nullptr;
        if (node == target)
            return copy;

        if (node->left != nullptr)
        {
            temp = searchTarget(node->left, copy->left, target);
            if (temp != nullptr)
                return temp;
        }
        if (node->right != nullptr)
        {
            temp = searchTarget(node->right, copy->right, target);
            if (temp != nullptr)
                return temp;
        }
        return nullptr;
    }
};