class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int len = 1;
        int cnt = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i - 1]){
                if(cnt == 0) cnt = 2;
                else if(cnt > 0) cnt++;
                else cnt = 2;
            }
            else if(nums[i] > nums[i - 1]){
                if(cnt == 0) cnt = -2;
                else if(cnt < 0) cnt--;
                else cnt = -2;
            }
            else cnt = 0;
            len = max(len, abs(cnt));
        }
        return len;
    }
};