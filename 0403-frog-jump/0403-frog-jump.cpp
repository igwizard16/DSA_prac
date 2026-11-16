class Solution {
public:
    bool cross(vector<int>& stones, vector<vector<int>>& dp, int idx, int k) {
        int n = stones.size();
        if (idx == n - 1)
            return true;
        if (dp[idx][k] != -1)
            return dp[idx][k];

        for(int jump = k - 1; jump <= k + 1; jump++){
            if(jump <= 0) continue;

            int nextPos = stones[idx] + jump;
            auto it = lower_bound(stones.begin(), stones.end(), nextPos);

            if(it != stones.end() && *it == nextPos){
                int nextIdx = it - stones.begin();

                if(cross(stones, dp, nextIdx, jump)){
                    return dp[idx][k] = true;
                }
            }
        }
        return dp[idx][k] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return cross(stones, dp, 0, 0);
    }
};