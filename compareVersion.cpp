string trimZero(string s)
{
    int i = 0;
    while(s[i]=='0') i++;
    //std::cout << s.substr(i, s.size()) << "\n";
    
    if (i<s.size()) return s.substr(i, s.size()-i);
    else return string("0");
}
int compareVersion(string version1, string version2) {
    version1 = trimZero(version1);
    version2 = trimZero(version2);
    int n1 = version1.find('.');
    int n2 = version2.find('.');
    int s1 = version1.size();
    int s2 = version2.size();
    
    string p1, p2;
    if (n1==-1) n1=s1; else p1= version1.substr(n1+1,s1-n1);
    if (n2==-1) n2=s2; else p2= version2.substr(n2+1,s2-n2);
    //std::cout << p1 << " " << p2 << "\n";
    if (n1>n2) return 1;
    else if (n1<n2) return -1;
    else
    {
    	int p1l = p1.size();
    	int p2l = p2.size();
		if (p1l > p2l) return 1;
		else if (p1l < p2l) return -1;
		else 
		{
			bool result = p1.compare(p2);
			return static_cast<int>(result);
		}
    }
    
}
