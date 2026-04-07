class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int score = 0, total_sum = 0;

        for(int x : cardPoints){
            total_sum += x;
        }
        if(n == k) return total_sum;

        int window_sum = 0;
        int m = n - k; //sliding window size
        for(int i = 0; i < m; i++){
            window_sum += cardPoints[i];
        }
        int min_sum = window_sum;
        for(int i = m; i < n; i++){
            window_sum += cardPoints[i];
            window_sum -= cardPoints[i - m];
            min_sum = min(min_sum, window_sum);
        }
        return total_sum - min_sum;
    }
};