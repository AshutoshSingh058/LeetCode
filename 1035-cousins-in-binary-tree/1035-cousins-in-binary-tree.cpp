class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        
        queue<pair<TreeNode*, TreeNode*>> q; // (node, parent)
        q.push({root, nullptr});
        
        TreeNode *px = nullptr, *py = nullptr;
        int hx = -1, hy = -1, depth = 0;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [node, parent] = q.front();
                q.pop();
                
                if (node->val == x) {
                    hx = depth;
                    px = parent;
                }
                if (node->val == y) {
                    hy = depth;
                    py = parent;
                }
                
                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }
            
            if (hx != -1 && hy != -1) 
                return (hx == hy && px != py); // Same depth, different parent
            
            depth++;
        }
        
        return false;
    }
};
