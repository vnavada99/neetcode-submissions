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

class Solution {
    int computeHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        int left = computeHeight(root->left);
        int right = computeHeight(root->right);
        return 1+ max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        // To be balanced
        return abs(computeHeight(root->left)-computeHeight(root->right)) <= 1
            && isBalanced(root->left)
            && isBalanced(root->right);;
    }
};
