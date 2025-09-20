//Implement using stack
//Modify to return them as a list

class Solution {
public:
    void dfs(TreeNode* root, int& cnt, int maxi)
    {
        if(!root) return;

        if(root->val >= maxi)
            cnt++;

        maxi = max(maxi, root->val);

        dfs(root->left, cnt, maxi);
        dfs(root->right, cnt, maxi);
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        dfs(root, cnt, root->val);
        return cnt;
    }
};
