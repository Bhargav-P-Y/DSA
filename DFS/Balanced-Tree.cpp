//If something is wrong then exit immediately
//Use -1 for false values etc

//Check if left subtree is imbalnced -> Yes ->exit
//Similarly for right
//THen for left & right

class Solution {
public:
    int height(TreeNode* root)
    {
        //Base cases
        if(!root) return 0;

        //Check if left subtree is imbalanced
        int lh = height(root->left);
        if(lh == -1) return -1;

        //Check if right subtree is imbalanced
        int rh = height(root->right);
        if(rh == -1) return -1;

        if(abs(lh-rh) > 1) return -1;

        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1; 
    }
};
