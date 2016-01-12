class Solution {
public:
    void strReverse(string& str)
    {   
        char t;
        int s = str.size();
        for (int i = 0; i < s/2; i++)
        {
            t = str[i];
            str[i] = str[s-i-1];
            str[s-i-1] = str[i];
        }
    }
    string addBinary(string a, string b) {
        bool inc = false;
        int as = a.size();
        int bs = b.size();
        int s = as < bs ? as : bs;
        int i = s - 1;
        string str;
        
        while (i >= 0)
        {
            if (inc)
            {
                if (a[i]=='0' && b[i]=='0')
                {
                    str+='1';inc=false;
                }
                    
                else if (a[i]=='1' && b[i]=='1')
                {
                    str+='1';inc=true;
                }
                else
                {   
                    str+='0';inc=true;
                }
                
            }
            else
            {
                if (a[i]=='0' && b[i]=='0')
                {
                    str+='0';inc=false;
                }
                    
                else if (a[i]=='1' && b[i]=='1')
                {
                    str+='0';inc=true;
                }
                else
                {   
                    str+='1';inc=false;
                }
            }
            
        }
        if (as == bs )
        {
            if (inc) str+='1'; 
        }
        else if (as > bs)
        {
            int m = as - bs -1;
            while (m>=0)
            {
                if (inc)
                {
                    if (a[m]=='0')
                    {
                        str+='1';inc=false;
                    
                    }
                    else
                    {
                        str+='0';inc=true;
                    }
                }
                else
                {
                    if (a[m]=='0')
                    {
                        str+='0';inc=false;
                    
                    }
                    else
                    {
                        str+='1';inc=false;
                    }
                }
            }
            
        }
        else
        {
            int m = bs - as -1;
            while (m>=0)
            {
                if (inc)
                {
                    if (b[m]=='0')
                    {
                        str+='1';inc=false;
                    
                    }
                    else
                    {
                        str+='0';inc=true;
                    }
                }
                else
                {
                    if (b[m]=='0')
                    {
                        str+='0';inc=false;
                    
                    }
                    else
                    {
                        str+='1';inc=false;
                    }
                }
            }
        }
        
        strReverse(str);
        return str;
    }
};
