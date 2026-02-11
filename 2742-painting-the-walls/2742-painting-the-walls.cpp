class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        const int INF = 1e9;

        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for(int i = 0; i < n; i++){
            int paint = 1 + time[i];
            for(int j = n; j >= 0; j--){
                if(dp[j] == INF) continue;

                int newPaint = min(n, j + paint);
                dp[newPaint] = min(dp[newPaint], dp[j] + cost[i]);
            }
        }
        return dp[n];
    }
};