class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0];
        int sum = 0;

        for(int i = 0; i < n; i++){
            mini = min(mini, nums[i]);
            sum += nums[i];
        }
        return sum - mini * n;
    }
};