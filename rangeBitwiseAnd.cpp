int rangeBitwiseAnd(int m, int n) {
    int diff = n - m;
    int mask = INT_MAX;
    int b = 1;
    while (diff > 0) {
        diff=diff>>1;
        mask=mask-1;
        b = b<<1;
    }
    return (mask & m);
}
