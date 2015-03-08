void resetMap(unordered_map<string, int> &map, vector<string> &L)
    {
        for (int i = 0; i < L.size(); i++) 
        {
            if ( map.find(L[i])==map.end() )
                map[L[i]] = 1;
            else
                map[L[i]] = map[L[i]]+1;
        }
    }
    
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string, int> map;
        vector<int> v;
        int len = L[0].length();
        int vs = L.size();
        resetMap(map, L);
        int n = 0;
        int cnt = 0;
        bool reset = false;
        while (n+len-1 < S.length())
        {
            string sstr = S.substr(n, len);
            while (map.find(sstr)==map.end() && (n+len-1) < S.length())
            {
                n++;
                sstr = S.substr(n, len);
                reset = true;
            }

            if ( (n+len-1) < S.length() )
            {
                if ( reset ) {resetMap(map, L); cnt=0; reset=false;}
                
                map[sstr]=map[sstr]-1;
                n = n + len;
                
                if (map[sstr]==0)
                {
                    cnt++;
                    if (cnt==vs) {v.push_back(n-vs*len); resetMap(map, L); cnt=0;}
                }
                else if (map[sstr]<0)
                {
                    resetMap(map, L);
                    map[sstr]=map[sstr]-1;
                    cnt = 1;
                }
                else
                {
                    cnt++;
                }
                
            }

        }
        return v;
        
    }
