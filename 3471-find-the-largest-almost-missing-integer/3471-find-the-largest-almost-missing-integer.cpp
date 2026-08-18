class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n){
            return *max_element(nums.begin(), nums.end());
        }

        if(k == 1){
            unordered_map<int, int> freq;
            for(int x : nums){
                freq[x]++;
            }
            int ans = -1;

            for(int x : nums){
                if(freq[x] == 1) ans = max(ans, x);
            }
            return ans;
        }

        int x = 0;
        int y = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == nums[0]) x++; 
            if(nums[i] == nums[n - 1]) y++;
        }

        bool x_unique = (x == 1);
        bool y_unique = (y == 1);

        if(x_unique && y_unique){
            return max(nums[0], nums[n - 1]);
        }
        if(x_unique) return nums[0];
        if(y_unique) return nums[n - 1];
        return -1;
    }
};  