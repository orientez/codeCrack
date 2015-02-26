void rotate(int nums[], int n, int k) {
    k = k % n;
    //std::cout << k << "\n";
    int *rotate = new int[k];
    
    for (int i = n - 1 ; i > n - k - 1; i--)
    {
        rotate[i - (n - k)] = nums[i];
        nums[i] = nums[i - k];
    }
    for (int i = n - k; i > k - 1; i--)
    {
    	nums[i] = nums[i - k];
    }
    for (int i = 0; i < k; i++)
    {
        nums[i] = rotate[i];
    }

    delete rotate;
}
