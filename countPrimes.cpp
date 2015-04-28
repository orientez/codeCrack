int countPrimes(int n) {
    if (n < 3) return 0;
    if (n == 3) return 1;
    int cnt = 1;
    vector<int> pv;
    pv.push_back(2);
    for (int i = 4; i <= n; i++)
    {
        
        int m = static_cast<int>(sqrt(i-1))+1;
        int pvs= pv.size();
        bool isPrime = false;
        int x = 0;
        while (pv[x] <= m && !isPrime && x < pvs)
        {
            if ( (i-1)%pv[x]==0 ) isPrime = true;
            x++;
        }
        if (isPrime) {pv.push_back(i-1);cnt++;}
    }
    return cnt;
}
