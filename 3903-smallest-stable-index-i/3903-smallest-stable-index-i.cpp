class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int stable = INT_MAX;
        int stable_idx = -1;

        for(int i = 0; i < n; i++){
            int maxi = *max_element(nums.begin(), nums.begin() + i + 1);
            int mini = *min_element(nums.begin() + i, nums.end());
            int score = maxi - mini;

            if(score <= k){
                return i;
            }
        }
        return -1;
    }
};