    string strTostr(string str)
    {
        int cnt = 1;
        string result;
        for(int i = 0; i < str.length() -1 ; i++)
        {
            if (str[i]==str[i+1]) 
            {
                cnt++;
            }
            else
            {
                result.append(1, (char)cnt );
                result.append(1, str[i]);
                cnt = 1;
            }
        }
        
        result.append(1, (char)cnt );
        result.append(1, str[str.length() -1]);
        return result;
    }
    
    string countAndSay(int n) {
        string str;
        if (n==0) return str;
        
        str = "1";
        //if (n==1) return str;
        for (int i = 1; i <= n; i++)
        {
            str = strTostr(str);
        }
        return str;
    }
