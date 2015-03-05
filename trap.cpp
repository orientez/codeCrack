class Solution {
public:
    int trap(int A[], int n) {
        int max = 0;
        int sum = 0;
        int neg = 0;
        int start = 0;
        int end = 0;
        bool once = false;
        while (A[start] <= A[start+1] && start < n)
        {
            start++;
        }
        max = start;

        for (int i = start+1; i < n; i++)
        {
            
            if (A[i] < A[max]) 
            {
                sum = sum + A[max] - A[i];
            }
            
            else
            {
                max = i;   
                once =true;
            }
        }
        if (!once) sum = 0;
        
        if (max < n - 1)
        {
            
            
            int k = n - 1;
            while (A[k] < A[k-1] && k > max) k--;
            end = k;
            
            
            for (int i = max+1; i < end; i++)
            {
                if (A[i] < A[end]) sum = sum + A[end] - A[i];
            }
        }
        
        
        return sum;
    }
};
