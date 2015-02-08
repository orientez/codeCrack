class Solution {
public:
    
    
    string trimZero(string s)
    {
        int i = 0;
        while(s[i]=='0') i++;
        if (i<s.size()) return s.substr(i, s.size()-1);
        else return string("0");
    }
    int compareVersion(string version1, string version2) {
        version1 = trimZero(version1);
        version2 = trimZero(version2);
        int n1 = version1.find('.');
        int n2 = version2.find('.');
        int s1 = version1.size();
        int s2 = version2.size();
        if (n1==0) n1=s1;
        if (n2==0) n2=s2;
        
        if (n1>n2) return 1;
        else if (n1<n2) return -1;
        else
        {
            int result = version1.substr(0, n1).compare(version2.substr(0, n2));
            if (result==0 && s1>n1)
                return version1.substr(n1, s1-1).compare(version2.substr(n2, s2-1));
            else
                return result;
        }
        
    }
};
