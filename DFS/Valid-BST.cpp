//Recursively
// dfs(root->left, left, root.val)
// dfs(root->right, root.val, right)

//Iteratively: Inorder traversal: Check if sorted

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* cur = root, *pred = nullptr, *prev = nullptr;

        while(cur)
        {
            if(cur->left)
            {
                pred = cur->left;
                while(pred->right && pred->right != cur)
                    pred = pred->right;
                
                if(pred->right)
                {
                    pred->right = nullptr;
                    if(prev && prev->val >= cur->val)
                        return false;
                    prev = cur;
                    cur = cur->right;
                }
                else
                {
                    pred->right = cur;
                    cur = cur->left;
                }
                    
            }
            else
            {
                if(prev && prev->val >= cur->val)
                    return false;
                prev = cur;
                cur = cur->right;
            }
            
        }
        return true;
        
    }
};
