bool isPalindrome(string s) {
    int ss = s.size();
    int left = 0;
    int right = ss - 1;
    while (left < right) {
        while (!isalpha(s[left]) && left < right) left++;
        while (!isalpha(s[right]) && left < right) right--;
        if (left==right) return true;
        
        if ( toupper(s[left]) == toupper(s[right]) ) {left++; right--;}
        else return false;
    }
    return true;
}
