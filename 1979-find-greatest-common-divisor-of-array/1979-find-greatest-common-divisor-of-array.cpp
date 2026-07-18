class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int gcd = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < mini) mini = nums[i];
            if(nums[i] > maxi) maxi = nums[i];
        }

        int a = maxi, b = mini;
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};