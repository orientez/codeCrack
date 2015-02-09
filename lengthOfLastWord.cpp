class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int si = 0;
        int i = 0;
        while(s[i])
        {
            i++;
            if (s[i]==' ') si = i;
        }
        return (i-si);
    }
};
