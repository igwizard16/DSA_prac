class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int operations = 0;

        for(int x : nums){
            int need = k - x;

            if(freq[need] > 0){
                freq[need]--;
                operations++;
            }
            else freq[x]++;
        }
        return operations;
    }
};