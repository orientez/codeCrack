int lengthOfLastWord(const char *s) {
    int si = 0;
    int i = 0;
    while(s[i])
    {
        i++;
        // if (s[i]==' ') std::cout << i << "\n";
    }
    i--;
    while(s[i]==' ')
    {
    	i--;
    }
    
    while(s[i]!=' ')
    {
    	si++;
    	i--;
    }
    return si;
}
