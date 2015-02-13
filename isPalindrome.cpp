    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        
        int base = 10;
        
        int nd = 0;
        int cpx = x;
        while (cpx > 0)
        {
            nd++;
            cpx = cpx / base;
        }
        
        int maxBase = static_cast<int>(pow(10, nd-1));
        int h, l;
        
        for (int i = 0; i <=(nd-1)/2; i++)
        {
            h = x / maxBase;
            l = x % base;
            if (x % maxBase==0 && i!=0) return true;
            
            if ((h*base/10)!=l) return false;
            x = x - h * maxBase - l * (base / 10);
            
            maxBase = maxBase / 10;
            base = base * 10;
        }
        return true;
    }
