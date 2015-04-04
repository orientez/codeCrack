int largestRectangleArea(vector<int> &height) {
    stack<int> iStack;
    int hs = height.size();
    int mArea = 0;
    for (int i = 0; i < hs; i++)
    {
        if (iStack.empty() || height[i] >= iStack.top())
        {
            iStack.push(i);
        }
        else
        {
            //int localMax = 0;
            //int k = i;
            while (iStack.size()>1 && height[i] < iStack.top() )
            {
                int tempi = iStack.top();
                iStack.pop();
                
                mArea = max(mArea, height[tempi]*(i-iStack.top()-1));
            }
            if (iStack.size()==1 && height[i] < iStack.top())
            {
                mArea = max(mArea, height[iStack.top()]*i);
                iStack.pop();
            }
                
            iStack.push(i);
        }
    }
    while (iStack.size()>1)
    {
        int tempi = iStack.top();
        iStack.pop();
        mArea = max(mArea, height[tempi]*(hs-iStack.top()-1));
    }
    if (!iStack.empty()) mArea = max(mArea, height[iStack.top()]*hs );
    
    return mArea;
    
}
