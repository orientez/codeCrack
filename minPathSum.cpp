int minPathSum(vector<vector<int> > &grid) {
    int m = grid.size();
    if (m==0) return 0;
    vector<int> v = grid[m-1];
    int n = grid[0].size();
    //if (m==1 && n==1) return 0;
    for (int k = n - 2; k >= 0; k--) v[k] = v[k] + v[k+1];

    for (int i = m - 2; i >= 0 ; i--)
    {
        v[n-1] = grid[i][n-1] + v[n-1];
        for (int j = n - 2; j >= 0; j--)
        {
            int mm = grid[i][j] < v[j+1] ? grid[i][j] : v[j+1];
            v[j] =  mm + v[j];
        }
        
    }
    return v[0];
}
