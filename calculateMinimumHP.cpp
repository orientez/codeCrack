    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int vvs = dungeon.size();
        if (vvs==0) return 0;
        int vs = dungeon[0].size();
        vector<int> mv(vs, 1);
        vector<int> av(vs, 1);
        int temp, temp1;
        
        av[0] = 1 - dungeon[0][0];
        if (av[0] > 0) mv[0] = av[0];
        else mv[0] = 1;
        
        for (int j = 1; j < vs; j++)
        {
            temp = av[j-1] -dungeon[0][j];
            mv[j] = max(mv[0], temp);
            av[j] = temp;
        }
        
        for (int i = 1; i < vvs; i++)
        {
            temp = av[0] - dungeon[i][0];
            mv[0] = max(mv[0], temp);
            av[0] = temp;
            
            for (int j = 1; j < vs; j++)
            {
                temp = av[j] - dungeon[i][j];
                temp1 = av[j-1] - dungeon[i][j];
                av[j] = min(temp, temp1);
                mv[j] = min(max(temp, mv[j]), max(temp1, mv[j-1]) );
            }
            
        }
        return mv[vs-1];
    }
