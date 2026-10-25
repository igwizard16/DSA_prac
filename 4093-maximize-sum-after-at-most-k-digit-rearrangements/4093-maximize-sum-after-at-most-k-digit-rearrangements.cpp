class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        
        vector<int> rearrange;

        for(int i = 0; i < n; i++){    
            sum += nums[i];
            
            vector<int> digits;
            int x = nums[i];
            while(x > 0){
                int digit = x % 10;
                digits.push_back(digit);
                x /= 10;
            }
            sort(digits.begin(), digits.end(), greater<int>());

            long long rearranged = 0;
            for(int j : digits){
                rearranged = rearranged * 10 + j;
            }
            rearrange.push_back(rearranged - nums[i]);
        }

        sort(rearrange.begin(), rearrange.end(), greater<int>());
        for(int i = 0; i < k && i < rearrange.size(); i++){
            sum += rearrange[i];
        }
        return sum;
    }
};