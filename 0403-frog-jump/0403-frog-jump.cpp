class Solution {
public:

    bool cross(vector<int>& stones,
               vector<vector<int>>& dp,
               unordered_map<int,int>& mp,
               int idx, int k) {
        int n = stones.size();

        if(idx == n-1)
            return true;

        if(dp[idx][k] != -1)
            return dp[idx][k];

        for(int jump = k-1; jump <= k+1; jump++) {
            if(jump <= 0)
                continue;

            int nextPos = stones[idx] + jump;
            if(mp.find(nextPos) != mp.end()) {
                int nextIdx = mp[nextPos];
                if(cross(stones, dp, mp, nextIdx, jump))
                    return dp[idx][k] = true;
            }
        }
        return dp[idx][k] = false;
    }

    bool canCross(vector<int>& stones) {

        int n = stones.size();
        if(stones[1] != 1)
            return false;
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++)
            mp[stones[i]] = i;

        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return cross(stones, dp, mp, 0, 0);
    }
};