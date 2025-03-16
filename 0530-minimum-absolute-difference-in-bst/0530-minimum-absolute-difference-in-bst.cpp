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
    // vector<int> inorder(TreeNode*root, vector<int>&v){


    //     return v;
    // }
    vector<int> inorder(TreeNode* root, vector<int>&v) {
       
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while (curr || !st.empty()) {
            while (curr) {  // Reach the leftmost node
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); st.pop();  // Process the node
            v.push_back(curr->val);   // Print value
            curr = curr->right;  // Move to the right subtree
        }
        return v;
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        v = inorder(root, v);
        int n =  v.size();
        int d= INT_MAX;
        for(int i=0; i<n-1; i++){
            d= min(d, v[i+1]-v[i]);
        }
        return d;
    }
};