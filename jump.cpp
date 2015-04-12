int jump(int A[], int n) {
    vector<int> mj(n, 0);
    mj[0] = 1;
    int mi = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i]+i>=n-1) return mj[i];
        
        for(int k = mi+1; k <= A[i]+i, i+k<n; k++)
        {
                mj[k] = mj[i]+1;
        }
        mi = i + A[i];
    }
    return mj[n-1]-1;
}
