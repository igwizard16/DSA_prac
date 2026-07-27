class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int minP = nums[0];
        int maxP = nums[0];
        int ans = nums[0];

        for(int i = 1; i < n; i++){

            if(nums[i] < 0) swap(maxP, minP);

            maxP = max(nums[i], nums[i] * maxP);
            minP = min(nums[i], nums[i] * minP);

            ans = max(ans, maxP);

        }
        return ans;
    }
};