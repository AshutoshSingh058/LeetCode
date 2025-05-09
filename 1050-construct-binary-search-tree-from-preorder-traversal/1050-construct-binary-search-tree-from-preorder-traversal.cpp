class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);

        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* node = new TreeNode(preorder[i]);
            TreeNode* parent = nullptr;
            while (!st.empty() && preorder[i] > st.top()->val) {
                parent = st.top();
                st.pop();
            }
            if (parent) {
                parent->right = node;
            } else {
                st.top()->left = node;
            }
            st.push(node);
        }
        return root;
    }
};
