void inOrder(TreeNode *root, TreeNode *p1, TreeNode *p2, TreeNode *pre)
{
    if (root)
    {
        if (p1==NULL || p2==NULL)
        {
            inOrder(root->left, p1, p2, pre);
            if (pre==NULL) pre = root;
            else
            {
                // check mistake
                if (pre->val > root->val)
                {
                    if (p1==NULL) p1 = pre; else p2 = pre;
                }
                pre=root;
            }
            inOrder(root->right, p1, p2, pre);
        }

    }
}

void recoverTree(TreeNode *root) {
    if (root==NULL) return;
    
    TreeNode *p1 = NULL;
    TreeNode *p2 = NULL;
    TreeNode *pre = NULL;
    inOrder(root, p1, p2, pre);
    if (p2==NULL) p2=pre;
    int temp = p1->val;
    p1->val = p2->val;
    p2->val = temp;
}
