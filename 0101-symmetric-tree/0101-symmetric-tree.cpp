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
    bool isSymmetric(TreeNode* root) {
        return (root==NULL) || isSymHelp(root->left, root->right);
    }
    bool isSymHelp(TreeNode* l, TreeNode* r){
        if(l ==nullptr || r== nullptr)return l == r ;
        if(l->val != r->val) return false;
        return isSymHelp(l->left, r->right) && isSymHelp(l->right, r->left);
    }
};