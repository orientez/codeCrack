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
    int sumNumbers(TreeNode *root) {
        stack<TreeNode*> treeStack;
        if (root==NULL) return 0;
        if (root->left==NULL && root->right==NULL) return root->val;
        int sum = 0;
        if (root->right==NULL) sum = -(root->val);
        
        treeStack.push(root);
        
        while (!treeStack.empty())
        {
            while (root->left)
            {
                root->left->val = root->val * 10 + root->left->val;
                root = root->left;
                treeStack.push(root);
            }
            
            while (!treeStack.empty())
            {
                root = treeStack.top();   
                if (root->right) 
                {
                    //root = treeStack.top();
                    treeStack.pop();
                    root->right->val = root->val * 10 + root->right->val;
                    root = root->right; 
                    treeStack.push(root);
                }
                else
                {
                    sum = sum + root->val;
                    treeStack.pop();
        
                }
            }
        }
        return sum;
    }
};
