class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        int maxp = nums[0];

        for(int i = 0; i < n; i++){
            prod = prod * nums[i];
            maxp = max(prod, maxp);

            if(prod == 0) prod = 1;
        }

        prod = 1;
        for(int i = n - 1; i >= 0; i--){
            prod = prod * nums[i];
            maxp = max(prod, maxp);
            if(prod == 0) prod = 1;
        }
        return maxp;
    }
};