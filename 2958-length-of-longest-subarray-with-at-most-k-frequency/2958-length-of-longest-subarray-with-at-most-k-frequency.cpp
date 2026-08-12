class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        int left = 0;
        int length = 0;

        for(int right = 0; right < n; right++){
            freq[nums[right]]++;
            
            while(freq[nums[right]] > k){
                freq[nums[left]]--;
                left++;
            }
            length = max(length, right - left + 1);
        }
        return length;
    }
};