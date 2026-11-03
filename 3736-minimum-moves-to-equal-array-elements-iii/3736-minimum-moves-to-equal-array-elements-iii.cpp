class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            maxi = max(maxi, nums[i]);
        }
        return maxi * n - sum;
    }
};