//Inorder & decrement k
// Follow ups:
// 1. Implement recursively: Inorder helper
// 2. kth largest, flip left to right


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        //Time complexity: O(n), n is the number of nodes in the tree
        //Space complexity: O(1), as we are only modifying pointers, 
        //no call stack or extra data structure
        
        TreeNode* cur = root, *pred = nullptr;

        while(cur)
        {
            if(cur->left)
            {
                pred = cur->left;
                while(pred->right && pred->right != cur)
                    pred = pred->right;
                if(pred->right)
                {
                    if(--k == 0) return cur->val;
                    pred->right = nullptr;
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
                if(--k == 0) return cur->val;
                cur = cur->right;
            }
        }
        //Won't reach here
        return -1;
        
    }
};

//Recursive

class Solution {
public:
    void inorder(TreeNode* root, int& res, int& k)
    {
        if(!root) return;

        inorder(root->left, res, k);
        if(--k == 0)
        {
            res = root->val;
            return;
        }
        inorder(root->right, res, k);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        //TC: O(n)
        //SC: O(h), h is the height of the tree
        int res = 0;
        inorder(root, res, k);
        return res;
    }
};
