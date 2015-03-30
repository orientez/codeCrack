int divide(int dividend, int divisor) {
    // check overflow first
    if (divisor==-2147483648) return 0;
    if (divisor==1) return dividend;
    if (dividend==-2147483648) return dividend=-2147483647;
    
    bool isNeg = false;
    if (dividend < 0 && divisor < 0)
    {
        dividend = -dividend;
        divisor = -divisor;
    }
    else if (dividend > 0 && divisor < 0)
    {
        divisor = -divisor;
        isNeg = true;
    }
    else if (dividend < 0 && divisor > 0)
    {
        dividend = -dividend;
        isNeg = true;
    }
    
    int result = 0;
    bool isFound = false;
    while (!isFound)
    {
        int pred = 0;
        int curd = divisor;
        int preq = 0;
        int curq = 1;
        
        while (dividend - curq > 0)
        {
            preq = curq;
            curq = curq + curq;
            pred = curd;
            curd = curd + curd;
        }
        if (preq == 0) isFound = true;
        dividend = dividend - pred;
        result = result + preq;
    }
    
    if (isNeg) return -result;
    else return result;
}
