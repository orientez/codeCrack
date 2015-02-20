    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size()==0) return NULL;
        if (num.size()==1)
        {
            TreeNode *r = new TreeNode(num[0]);
            return r;
        }

        int first = 0;
        int last = num.size() - 1;
        int mid = (first + last) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        
        TreeNode *lPtr;
        TreeNode *rPtr;
        if (mid>0) 
        {
            vector<int> leftV(num.begin(), num.begin()+mid-1 );
            lPtr = sortedArrayToBST(leftV);
        }
        else
            lPtr = NULL;
           
        vector<int> rightV( num.begin()+mid+1, num.begin()+last );
        
        rPtr = sortedArrayToBST(rightV);
        root->left = lPtr; 
        root->right = rPtr;
        return root;
        
    }
