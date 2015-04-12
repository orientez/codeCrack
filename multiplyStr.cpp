string addc (string s, char c)
{
    string str;
    int carry = c-'0';
    for (int i = s.size()-1; i >= 0; i--)
    {
        carry = (carry + s[i] - '0')/10;
        char c = (carry + s[i] - '0')%10 + '0'; 
        str = c + str;
    }
    return str;
}

string add(string n1, string n2)
{
    int s1 = n1.size();
    int s2 = n2.size();
    int i = s1 - 1;
    int j = s2 - 1;
    string str;
    int carry = 0;
    while (i >= 0 && j >=0)
    {
        carry = (carry + n1[i] - '0' + n2[j] - '0')/10;
        char c = (carry + n1[i] - '0' + n2[j] - '0')%10 + '0'; 
        str = c + str;
        i--;
        j--;
    }
    

    char t = carry + '0';
    string tstr;
    if (i >= 0) 
    {
        tstr = addc(n1.substr(0, i+1), t);
    }
    if (j >= 0) 
    {
        tstr = addc(n2.substr(0, j+1), t);
    }
    str = tstr + str;

    return str;
}

string multiplyc (string s, char c)
{
    string str;
    int carry = 0;
    for (int i = s.size()-1; i >=0; i--)
    {
        char t = ((s[i]-'0')*(c-'0') + carry )%10 + '0';
        carry =  ((s[i]-'0')*(c-'0') + carry )/10;
        str = t + str;
    }
    
    if (carry > 0) 
    {
        char t = carry + '0';
        str = t + str;
    }
    return str;
    
}

string multiply(string num1, string num2) {
    string ret = num1;
    ret = multiplyc(ret, num2[0]);
    for (int k = 0; k < num2.size() - 1; k++) ret+='0';
    
    
    
    for (int i = 1; i < num2.size(); i++)
    {
        string str = num1;
        str = multiplyc(str, num2[i]);
        for (int k = 0; k < num2.size() - i - 1; k++) str+='0';
        ret = add(ret, str);
    }
    return ret;
}
