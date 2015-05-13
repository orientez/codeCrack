bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;
    int base = 1;
    while (x/10 >= base) {
        base = base * 10;
    }
    //base = base/10;
    while (x > 0) {
        if (x < 10) return true;
        if (x/base==x%10)
        {
            x = x%base;
            x = x/10;
            base = base/100;
        }
        else
            return false;
        
    }
    return true;
