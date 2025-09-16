//THink from base case
//Follow up: THe path with the most depth

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1+ max(lh, rh);
        
    }
};
