class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();

        int Reven = 0;
        int Rodd = 0;

        for(int i = 0; i < n; i++){
            if(i % 2 == 0) Reven += nums[i];
            else Rodd += nums[i];
        }

        int Leven = 0;
        int Lodd = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(i % 2 == 0) Reven -= nums[i];
            else Rodd -= nums[i];

            //switch parity
            int newEven = Leven + Rodd;
            int newOdd = Lodd + Reven;

            if(newEven == newOdd) cnt++;

            if(i % 2 == 0) Leven += nums[i];
            else Lodd += nums[i];
        }
        return cnt;
    }
};