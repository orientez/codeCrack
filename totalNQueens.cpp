class Solution {
    
    struct Pos{
      int r;
      int c;
      Pos(int x, int y) : r(x), c(y) {}
    };
public:

    bool isUnderAttack(Pos p, vector<Pos> pre)
    {
        for (int i = 0; i < pre.size(); i++)
        {
            if ( p.r==pre[i].r || p.c==pre[i].c || (p.r - pre[i].r)==(p.c - pre[i].c) ) return true;
        }
        return false;
    }
    
    int totalNQueens(int n) {
        if (n==0) return 0;
        vector<Pos> moves;
        int cnt = 0;
        Pos cur(0,0);
        
        do
        {
            if (!isUnderAttack(cur, moves))
            {
                moves.push_back(cur);
                if (cur.c + 1 >= n) 
                {
                    cnt++;
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
            
            
        } while ( moves.size() > 0 ) ;
        
        return cnt;
    }
};
