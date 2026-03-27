class Solution {
public:
    void generate(int idx, int k, int n, vector<int>& ds, vector<vector<int>>& ans){
        if(n == 0 && (int)ds.size() == k){
            ans.push_back(ds);
            return;
        }
        if((int)ds.size() == k || n < 0) return;

        for(int i = idx; i <= 9; i++){
            ds.push_back(i);
            generate(i + 1, k, n - i, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        generate(1, k, n, ds, ans);
        return ans;
    }
};