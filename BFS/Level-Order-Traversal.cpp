//perform BFS
//emplace_back to avoid unecessary copying


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> lvls;
        if(!root) return lvls;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            int len = q.size();
            vector<int> lvl;
            
            for(int i = 0;i<len;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                lvl.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            lvls.emplace_back(lvl);
        }
        return lvls;
        
    }
};
