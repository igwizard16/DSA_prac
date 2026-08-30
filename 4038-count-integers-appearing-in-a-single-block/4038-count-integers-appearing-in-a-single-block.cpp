class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(int i = 0; i < nums.size(); i++){
            if(i == 0 || nums[i - 1] != nums[i]){
                mpp[nums[i]]++;
            }
        }

        int ans = 0;

        for(auto[x, blocks] : mpp){
            if(blocks == 1) ans++;
        }
        return ans;
    }
};