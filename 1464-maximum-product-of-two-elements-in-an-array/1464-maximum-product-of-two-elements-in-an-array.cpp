class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int idx = 0;

        //1st max
        for(int i = 0; i < n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                idx = i;
            }
        }

        //2nd max
        int maxi_2 = INT_MIN;
        for(int i = 0; i < n; i++){
            if(idx == i) continue;
            maxi_2 = max(maxi_2, nums[i]);
        }
        return (maxi - 1) * (maxi_2 - 1);
    }
};