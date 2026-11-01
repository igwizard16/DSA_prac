class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), []
        (const auto& a, const auto& b){
            if(a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });

        int remove = 0;
        int last = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] < last){
                remove++;
            }
            else{
                last = intervals[i][1];
            }
        }
        return remove;
    }
};