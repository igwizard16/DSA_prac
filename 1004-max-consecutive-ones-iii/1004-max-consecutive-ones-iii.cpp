class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroes = 0;
        int max_len = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == 0){
                zeroes++;
            }
            while(zeroes > k){
                if(nums[left] == 0){
                    zeroes--;
                }
                left++;
            }
            max_len = max(right - left + 1, max_len);
        }
        return max_len;
    }
};