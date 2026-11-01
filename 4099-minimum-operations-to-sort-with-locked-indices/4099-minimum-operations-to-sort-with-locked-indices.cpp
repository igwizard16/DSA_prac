class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int unlocks = 0;
        int prefixMax = 0;

        for(int i = 0; i < n; i++){
            prefixMax = max(prefixMax, nums[i]);
            if(locked[i] == 1 && (nums[i] != i + 1 || prefixMax > i + 1)) unlocks++;
        }
        if(unlocks > k) return -1;

        int inversions = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] > nums[j]) inversions++;
            }
        }
        return unlocks + inversions;
    }
};