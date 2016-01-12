    // ")(((((()())()()))()(()))("
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int lvp = 0;
        int clvp = 0;
        int i = 0;
        int ss = s.size();
        int lleft = 0;
        while (i < ss)
        {
            if (s[i]=='(')
            {
                left++;
            }
            else if (s[i]==')')
            {
                right++;
            }
            // check current
            if (left<right)
            {
                clvp = left + left;
                lvp = max(clvp, lvp);
                left = 0;
                right = 0;
            }
            else if (left==right)
            {
                clvp = left + left;
                lvp = max(lvp, clvp);
            }
            else
            {
                if (s[i]=='(')
                {
                    lleft++;
                }
                else if (s[i]==')') 
                {
                    if (lleft>1)
                    {
                        lleft=0;
                        clvp = 2;
                    }
                    else
                    {
                        lleft=0;
                        clvp = clvp + 2;
                    }
                    lvp = max(lvp, clvp);
                }
            }
            i++;
        }
        return lvp;

    }
