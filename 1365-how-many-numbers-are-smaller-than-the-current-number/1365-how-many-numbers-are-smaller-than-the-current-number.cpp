class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        vector<int> res;
        unordered_map<int, int> mp;

        mp[temp[0]] = 0;
        for(int i = 1; i < n; i++){
            if(temp[i - 1] == temp[i]) continue;
            mp[temp[i]] = i;
        }
        for(auto num : nums){
            res.push_back(mp[num]);
        }
        return res;
    }
};