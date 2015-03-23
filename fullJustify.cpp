    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> vstr;
        if (L==0) 
        {
            for (int i = 0; i < words.size(); i++)
            {
                if (words[i].size()==0)
                    vstr.push_back(words[i]);
                else
                {
                    vector<string> vstrEmpty;
                    return vstrEmpty;
                }
            }
            return vstr;
        }
        int len = -1;
        int pi = 0;
        int diff; 
        int q, r;
        
        for (int i = 0; i < words.size(); i++)
        {
            len = len + words[i].size() + 1;
            if (len > L)
            {
                len = len - words[i].size() + 1;
                
                string str;
                if (i-1-pi==0)
                {
                    // append empty spaces to the end
                    str=words[i-1];
                    int sl = str.length();
                    for (int l = 0; l < L - sl; l++)
                        str+=" ";
                    
                }
                else
                {
                    diff = L - len;
                    q = diff/(i-pi-1);
                    r = diff%(i-pi-1);
                    
                    for (int k = pi; k < i - 1; k++)
                    {
                        str+=words[k];
                        for (int l = 0; l < q; l++)
                            str += " ";
                        
                        if (r > 0) {str+=" "; r--;}
                    }
                    
                    str+=words[i-1];
                }
                vstr.push_back(str);
                
                pi = i;
                len = words[i].size();
                
            }
            else if (len == L)
            {
                string str;
                for (int k = pi; k < i; k++)
                {
                    str= str + words[k] + " ";
                }
                str = str + words[i];
                
                vstr.push_back(str);
                
                pi = i + 1;
                len = -1;
            }
            // else (len < L)   
            // keep appending 
        }
        
        // last line
       
        if ( pi < words.size() )
        {
            string str;
            for (int k = pi; k < words.size() - 1; k++)
            {
                str= str + words[k] + " ";
            }
            str = str + words[words.size()-1];
            int sl = str.length();
            for (int l = 0; l < L - sl; l++)
                str+=" ";
            vstr.push_back(str);
        }
        
        
        return vstr;
    }
