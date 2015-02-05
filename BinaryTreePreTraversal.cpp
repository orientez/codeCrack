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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> vec;
        if (root==NULL) return vec;
        vec.push_back(root->val);
        vector<int> pre_vec = preorderTraversal(root->left);
        vec.insert( vec.end(), pre_vec.begin(), pre_vec.end() );
        vector<int> post_vec =preorderTraversal(root->right);
        vec.insert( vec.end(), post_vec.begin(), post_vec.end() );
        return vec;
    }
};
