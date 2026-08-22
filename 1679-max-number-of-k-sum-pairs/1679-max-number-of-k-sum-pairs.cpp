class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int operations = 0;

        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }

        for(int x : nums){
            if(freq[x] == 0) continue;
            int pair = k - x;

            if(freq[pair] == 0) continue;
            if(x == pair && freq[x] < 2) continue;

            freq[x]--;
            freq[pair]--;
            operations++;
        }
        return operations;
    }
};