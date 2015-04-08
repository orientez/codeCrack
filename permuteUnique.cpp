void perm(vector<vector<int> >& res, int cur, vector<int> &num)
{
    if (cur == num.size()-1) 
    {
        res.push_back(num);
        return;
    }
    for (int i = cur; i < num.size(); i++)
    {
        if (i==cur) perm(res, cur+1, num);
        else if (num[cur]!=num[i])
        {
            swap(num[cur], num[i]);
            perm(res, cur+1, num);
            swap(num[cur], num[i]);
        }
    }
}

vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int> > vv;
    perm(vv, 0, num);
    return vv;
}
