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
    vector<int> inorderTraversal(TreeNode* root) {
        // inorder : left - root - right
        vector<int> v;
        if (root == NULL) return v;
        stack <TreeNode*> st;
        while(root ||!st.empty()){
            if(root)st.push(root);
            while(root && root->left){
                root= root->left;
                st.push(root);
            }
            root = st.top();
            st.pop();
            v.push_back(root->val);
            root= root->right;
        }

        return v;
    }
};