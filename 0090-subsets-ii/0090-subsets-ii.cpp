class Solution {
public:
    void powerset(int idx, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans){
        ans.push_back(ds);
        
        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            powerset(i + 1, nums, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int idx = 0;
        vector<int> ds;
        vector<vector<int>> ans;
        powerset(idx, nums, ds, ans);
        return ans;
    }
};