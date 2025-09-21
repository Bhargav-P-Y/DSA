//THink small: Base case
//Preorder tells which node is next
//Inorder tells if it is in the left or right
//Repeat this recursively

class Solution {
public:
    TreeNode* build(unordered_map<int, int>& inIdx, vector<int>& preorder, int& preIdx, int left, int right)
    {
        if(left>right) return nullptr;

        int rootVal = preorder[preIdx];
        preIdx++;
        TreeNode* root = new TreeNode(rootVal);

        root->left = build(inIdx, preorder, preIdx, left, inIdx[rootVal]-1);
        root->right = build(inIdx, preorder, preIdx, inIdx[rootVal]+1, right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inIdx;
        int n = inorder.size();

        for(int i = 0;i<n;i++)
            inIdx[inorder[i]] = i;
        int preIdx = 0;
        return build(inIdx, preorder, preIdx, 0, n-1);
        
    }
};
