//Keeping a separate lvl vector only to store the last one is a waste
//Keeping an extra cnt variable is also redundant
//Use the index itself!

//For left-side, just check if i ==0 or not

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rsv;
        if(!root) return rsv;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            int len = q.size();

            for(int i = 0;i<len;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(i == len -1)
                    rsv.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return rsv;
        
    }
};
