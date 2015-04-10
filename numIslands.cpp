bool isValid(int x, int y, int nrows, int ncols)
{
    return (x >= 0 && y >= 0 && x < nrows && y < ncols);
}

void bfs(vector<vector<char> > &grid, vector<vector<bool> >& isVisited, int i, int j)
{
    pair<int, int> pos(i, j);
    queue<pair<int, int>> iqueue;
    iqueue.push(pos);

    while (!iqueue.empty())
    {
        pair<int, int> pos = iqueue.front();
        iqueue.pop();
        int x = pos.first;
        int y = pos.second;
        int nrows = grid.size();
        int ncols = grid[0].size();
        
        if (isValid(x+1, y, nrows, ncols))
        {
            if (!isVisited[x+1][y])
            {
                iqueue.push(make_pair(x+1, y));
                isVisited[x+1][y] = true;
            }
        }   
        if (isValid(x-1, y, nrows, ncols))
        {
            if (!isVisited[x-1][y])
            {
                iqueue.push(make_pair(x-1, y));
                isVisited[x-1][y] = true;
            }    
        }
        if (isValid(x, y+1, nrows, ncols))
        {
            if (!isVisited[x][y+1])
            {
                iqueue.push(make_pair(x, y+1));
                isVisited[x][y+1] = true;
            }
        }    
        if (isValid(x, y-1, nrows, ncols))
        {
            if (!isVisited[x][y-1])
            {
                iqueue.push(make_pair(x, y-1));
                isVisited[x][y-1] = true;
            }
        }
    }
    
}

int numIslands(vector<vector<char>> &grid) {
    int nrows = grid.size();
    if (nrows==0) return 0;
    int cols = grid[0].size();
    vector<bool> vb(cols, false);
    vector<vector<bool> > isVisited(nrows, vb);
    int nIsland=0;
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!isVisited[i][j] && grid[i][j]==1)
            {
                isVisited[i][j] = true;
                bfs(grid, isVisited, i, j);
                nIsland++;
            }
        }
    }
    return nIsland;
    
}
