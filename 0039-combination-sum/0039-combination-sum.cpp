class Solution {
public:
    void findcombination(int idx, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds){
        if(idx == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[idx] <= target){
            ds.push_back(candidates[idx]);
            findcombination(idx, target - candidates[idx], candidates, ans, ds);
            ds.pop_back();
        }
        findcombination(idx + 1, target, candidates, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findcombination(0, target, candidates, ans, ds);
        return ans;
    }
};