class Solution {
public:
    void powerset(int idx, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back(ds);
            return;
        }
        if(idx < nums.size()){
            ds.push_back(nums[idx]);
            powerset(idx + 1, nums, ds, ans);
            ds.pop_back();
        }
        powerset(idx + 1, nums, ds, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int idx = 0;
        powerset(idx, nums, ds, ans);
        return ans;
    }
};