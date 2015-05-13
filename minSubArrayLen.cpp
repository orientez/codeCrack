// [5,1,3 ,5,10,7,4,9,2,8]
int minSubArrayLen(int s, vector<int>& nums) {
    int left = 0;
    int right = 0;
    int nn = nums.size();
    if (nn==0) return 0;
    int cur = nums[0];
    int m;
    int cnt = 1;
    while (right<nn && left<=right) {
        if (cur < s) {
            right++;
            cur = cur + nums[right];
            cnt++;
            m = cnt;
        }
        else {
            while (cur >= s) {
                cur = cur - nums[left];
                left++;
                cnt--;
            }
            m = min(m, cnt+1);
        }
    }
    if (left==0) return 0;
    else return m;
