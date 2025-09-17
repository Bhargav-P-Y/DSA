/One node out of all the nodes will contain
//the longest diameter --> (lh +rh)
//So go to every node
//Find its lh & rh
//Find dia by lh+rh
//Update if it's larger

class Solution {
public:
    int findHeight(TreeNode* root, int& dia)
    {
        if(!root) return 0;
        
        int lh = findHeight(root->left, dia);
        int rh = findHeight(root->right, dia);

        dia = max(dia, lh+rh);
        
        return  1+ max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        findHeight(root, dia);
        return dia;
        
    }
};
