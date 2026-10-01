class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        long long totalSum = 0;
        for(int x : nums){
            totalSum = (totalSum + x) % p;
        }
        
        int target = totalSum;
        if(target == 0) return 0;

        unordered_map<int, int> mpp;
        mpp[0] = -1;

        long long prefix = 0;
        int ans = n;

        for(int i = 0; i < n; i++){
            prefix = (prefix + nums[i]) % p;
            int currRem = prefix;
            
            int need = (currRem - target + p) % p;
            if(mpp.find(need) != mpp.end()){
                ans = min(ans, i - mpp[need]);
            }

            mpp[currRem] = i;
        }
        return ans == n ? -1 : ans;
    }
};