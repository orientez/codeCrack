class Solution {
public:
    string convertToTitle(int n) {
        string str;
        char c;
        int m ;
        // pay attention the corner cases when n is multiple of 26
        while (n > 0)
        {
            m = n % 26;
            if (m==0) 
            {
                c = 64 + 26;
                n = n / 26 -1;
            }
            else 
            {
                c = m + 64;
                n = n / 26;
            }
            
            str += c;
        }
        char tc;
        int len = str.length();
        for (int i = 0; i < len/2; i++)
        {
            tc = str[len-i-1];
            str[len - i - 1] = str[i];
            str[i] = tc;
            
        }
        return str;
    }
};
