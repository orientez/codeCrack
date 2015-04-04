int minDistance(string word1, string word2) {
    int s1 = word1.size();
    int s2 = word2.size();
    if (s1==0) return s2;
    vector<int> v(s2+1, 0);
    // v[0] = 1;
    int a, b, c;
    int pre;
    for (int i = 0; i < s1; i++)
    {
        pre = v[0];
        v[0] = i + 1;
        for (int j = 0; j < s2; j++)
        {
            a = v[j + 1] + 1;
            b = v[j] + 1;
            c = pre + ( (word2[j]==word1[i]) ? 0 : 1 );
            pre = v[j+1];
            v[j + 1] = min (min(a,b), c);
        }
    }
    return v[s2];
}
