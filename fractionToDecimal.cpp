string fractionToDecimal(int numerator, int denominator) {
    
    string ret;
    int q = numerator/denominator;
    ret = to_string(q);
    int r = numerator%denominator;
    if (r==0) return ret;
    ret = ret + ".";
    r = r * 10;
    
    q = r/denominator;
    r = r%denominator; 
    char c = q + '0';
    ret = ret + c;
    r = r * 10;
    string s;
    //bool isFound = false;
    int i1 = 0;
    while (s.size()!=2 * i1 || s.size()==0)
    {
        q = r/denominator;
        r = r%denominator;
        char c = q + '0';
        
        if (r==0) 
        {
            s = s + c;
            ret = ret + s;
            return ret;
        }
        if (s.size()==0) s = s + c;
        else
        {
            if (s[i1]==c) i1++;
            else i1 = 0;
            s = s + c;
        }
        
        r = r * 10;
        
    }
    s = s.substr(0, s.size()/2);
    ret = ret + "(" + s + ")";
    return ret;
}
