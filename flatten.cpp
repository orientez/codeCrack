/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recur(TreeNode *nodePtr)
    {
        if (nodePtr==NULL) return NULL;
        
        
        TreeNode *lPtr = recur(nodePtr->left);
        TreeNode *rPtr = recur(nodePtr->right);
        if (lPtr!=NULL) 
        {
            nodePtr->right = lPtr;
            while (lPtr->right!=NULL) lPtr = lPtr->right;
            lPtr->right = rPtr; 
        }
        
        else 
            nodePtr->right = rPtr;
            
        return nodePtr;
        
    }
    
    void flatten(TreeNode *root) {
        if (root==NULL) return;
        root = recur(root);
    }
};
