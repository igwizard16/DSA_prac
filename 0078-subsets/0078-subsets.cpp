class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerset;
        powerset.push_back({});
        for(int i = 0; i < nums.size(); i++){
            int curr = powerset.size();
            for(int j = 0; j < curr; j++){
                vector<int> newset = powerset[j];
                newset.push_back(nums[i]);
                powerset.push_back(newset);
            }
        }
        return powerset;
    }
};