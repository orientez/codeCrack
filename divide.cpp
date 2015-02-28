int divide(int dividend, int divisor) {
    //int sign1 = dividend >= 0 ? 1 : -1;
    //int sign2 = divisor >= 0 ? 1 : -1;
    if (dividend == 0 ) return 0;
    int r = 0;
    if ( dividend > 0 &&  divisor > 0)
    {
        while (dividend >= divisor)
        {
            if (r==0)
            {
                dividend >> 1;
                r=1;
            }
            else
            {
                dividend >> 1;
                r << 1;
            }
        }
        return r;
    }
    else if ( dividend > 0 &&  divisor < 0)
    {
        while (dividend + divisor >= 0)
        {
            if (r==0)
            {
                dividend >> 1;
                r=-1;
            }
            else
            {
                dividend >> 1;
                r << 1;
            }
        }
        return r;
    }
    else if ( dividend < 0 &&  divisor > 0)
    {
        while (dividend + divisor <= 0)
        {
            if (r==0)
            {
                dividend >> 1;
                r=-1;
            }
            else
            {
                dividend >> 1;
                r << 1;
            }
        }
        return r;            
    }
    else
    {
        while (dividend <= divisor)
        {
            if (r==0)
            {
                dividend >> 1;
                r=1;
            }
            else
            {
                dividend >> 1;
                r << 1;
            }
        }
        return r;            
    }
    
    
    
}
