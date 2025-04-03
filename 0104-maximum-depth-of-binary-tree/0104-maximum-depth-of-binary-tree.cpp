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
public:
    int inorder(int m, TreeNode* root){
        if(root == NULL)return m;
        return max(inorder(m+1, root->left), inorder(m+1, root->right));
    }

    int maxDepth(TreeNode* root) {
        int ans = inorder(0, root);
        return ans;
    }
};