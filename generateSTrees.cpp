    vector<TreeNode *> generateSTrees(int n, int start)
    {
        vector<TreeNode *> trees;
        if (n==0) 
        {
            trees.push_back(NULL); 
            return trees;
        }
        for (int i = start; i < n + start; i++)
        {
            // decide which is the root 
            TreeNode *tnPtr = new TreeNode(i);
            
            
            vector<TreeNode *> leftTrees = generateSTrees(i-start, start);
            vector<TreeNode *> rightTrees = generateSTrees(n+start-i-1, i+1);
            
            // cross iterate left and right trees
            for (int j = 0; j < leftTrees.size(); j++)
            {
                for(int k = 0; k < rightTrees.size(); k++)
                {
                    tnPtr->left = leftTrees[j];
                    tnPtr->right = rightTrees[k];
                    trees.push_back(tnPtr);
                }
            }
        }
        return trees;
        
    }
    
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *>  treeVector = generateSTrees(n, 1);
        return treeVector;
    }
