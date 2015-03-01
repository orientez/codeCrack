class Solution {
    
struct Pos{
  int r;
  int c;
  Pos(int x, int y) : r(x), c(y) {}
};

public:

    vector<string> moveToBoard(vector<Pos> moves, int n)
    {
        vector<string> board;
        char *str = new char[n];
        for (int i = 0; i < moves.size(); i++)
        {
            for (int j = 0; j < n; j++) str[j] = '.';
            str[moves[i].r] = 'Q';
            board.push_back(str);
        }
        delete [] str;
        return board;
    }

    bool isUnderAttack(Pos p, vector<Pos> pre)
    {
        for (int i = 0; i < pre.size(); i++)
        {
            if ( p.r==pre[i].r || p.c==pre[i].c || (p.r - pre[i].r)==(p.c - pre[i].c) || (p.r - pre[i].r) + (p.c - pre[i].c)==0 ) 
            return true;
        }
        return false;
    }
    
    vector<vector<string> > solveNQueens(int n) {
        
        vector<Pos> moves;
        vector<vector<string> > vv;
        if (n==0) return vv;
        Pos cur(0,0);
        
        do
        {
            if (!isUnderAttack(cur, moves))
            {
                moves.push_back(cur);
                if (cur.c + 1 >= n) 
                {
                    vv.push_back(moveToBoard(moves, n));
                    moves.pop_back();
                    cur.r = cur.r + 1;
                }
                else
                {
                    cur.c = cur.c + 1;
                    cur.r = 0;
                }
            }
            else
            {
                cur.r = cur.r + 1;
            }
            

            // backtrack here
            while (cur.r>=n && moves.size()>0)
            {
                cur = moves.back();
                moves.pop_back();
                //cur.c = cur.c - 1;
                cur.r = cur.r + 1;
            }
            
            
        } while ( moves.size() >= 0 && cur.r < n ) ;
        
        return vv;        
    }
};
