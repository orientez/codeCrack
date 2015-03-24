TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.size()==0) return NULL;
        
        TreeNode *root = new TreeNode(postorder[postorder.size()-1]);
        
        if (postorder.size()==1)  return root;

        unordered_map<int, int> mmap;
        for (int k = 0; k < inorder.size(); k++)
        {
            mmap[inorder[k]] = k;
        }
        
        TreeNode *cur = NULL;
        bool isLocated = false;
        for (int i = postorder.size()-2; i >= 0; i--)
        {
            cur = root;
            isLocated = false;
            while (!isLocated)
            {
                if ( mmap[postorder[i]] > mmap[postorder[cur->val]] )
                {
                    if (cur->right) 
                        cur = cur->right;
                    else
                    {
                        TreeNode *nptr = new TreeNode(postorder[i]);
                        cur->right = nptr;
                        isLocated = true;
                    }
                }
                else
                {
                    if (cur->left) 
                        cur = cur->left;
                    else
                    {
                        TreeNode *nptr = new TreeNode(postorder[i]);
                        cur->left = nptr;
                        isLocated = true;
                    }                    
                }
            }
            
        }
        return root;
    }
