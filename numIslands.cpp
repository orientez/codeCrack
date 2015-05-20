bool isValid(int x, int y, int mx, int my) {
    return (x >= 0 && x < mx && y >= 0 &&  y < my);
}

void bfs(const vector<vector<char>>& grid, vector<vector<bool> >& isVisited, int x, int y) {
    queue<pair<int, int> > coor;
    coor.push(make_pair(x, y));
    int mx = grid.size();
    int my = grid[0].size();
    while (!coor.empty()) {
        pair<int, int> p = coor.front();
        coor.pop();
        int next[4][2];
        next[0][0] = p.first+1;next[0][1] = p.second;
        next[1][0] = p.first-1;next[1][1] = p.second;
        next[2][0] = p.first;  next[2][1] = p.second+1;
        next[3][0] = p.first;  next[3][1] = p.second-1;
        
        for (int i = 0; i < 4; i++) {
            if ( isValid(next[i][0], next[i][1], mx, my ) ) {
                isVisited[next[i][0]][next[i][1]] = true;
                coor.push(make_pair(next[i][0], next[i][1]));
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (nr==0) return 0;
    int nc = grid[0].size();
    vector<vector<bool> > isVisited(nr, vector<bool>(nc, false));
    int nIslands = 0;
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            if (!isVisited[i][j] && grid[i][j]=='1') {
                nIslands++;
                isVisited[i][j] = true;
                bfs(grid, isVisited, i, j);
            }
        }
    }
    return nIslands;
}
