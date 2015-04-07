bool isValidIndex(vector<vector<char> > &board, vector<vector<bool> > isVisited, int i, int j)
{
    
    return  (i >= 0) && (j >= 0) && (i < board.size()) && (j < board[0].size()) && (!isVisited[i][j]);
}

bool search(vector<vector<char> > &board, string &word, string curWord, vector<vector<bool> > isVisited, int i, int j)
{
    
    
    if (curWord + board[i][j] == word) return true;
    if (board[i][j] == word[curWord.size()]);
    {
        isVisited[i][j] = true;
        if (isValidIndex(board, isVisited, i+1, j) )
            if (search(board, word, curWord+board[i][j], isVisited, i+1, j)) return true;
            
        if (isValidIndex(board, isVisited, i, j+1) )
            if (search(board, word, curWord+board[i][j], isVisited, i, j+1)) return true;
            
        if (isValidIndex(board, isVisited, i-1, j) )
            if (search(board, word, curWord+board[i][j], isVisited, i-1, j)) return true;
            
        if (isValidIndex(board, isVisited, i, j-1) )
            if (search(board, word, curWord+board[i][j], isVisited, i, j-1)) return true;
        
        return false;
    }
        
    return false;

}

bool exist(vector<vector<char> > &board, string word) {
    vector<bool> v(board[0].size(), false);
    
    vector<vector<bool> > isVisited(board.size(), v);
    
    return (search(board, word, "", isVisited, 0, 0));
}
