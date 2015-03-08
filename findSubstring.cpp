void resetMap(unordered_map<string, int> &map, vector<string> &L)
{
    map.clear();
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
    int start;
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
            if (map[sstr]==0)
            {
                cnt++;
                if (cnt==vs) 
                {
                    start = n-vs*len+len;
                    v.push_back(start); 
                    n = start + 1;
                    
                    resetMap(map, L); 
                    cnt=0;
                    
                }
            }
            else if (map[sstr]<0)
            {
                int temp = n - len;
                resetMap(map, L);
                map[sstr]=map[sstr]-1;
                cnt = 1;
                
                string str= S.substr(temp, len);
                while (str!=sstr)
                {
                    map[str]=map[str]-1;
                    temp = temp - len;
                    str= S.substr(temp, len);
                    cnt++;
                }
                n = n + len;
                
                
            }
            else
            {
                n = n + len;
                cnt++;
            }
            
        }

    }
    return v;
    
}
