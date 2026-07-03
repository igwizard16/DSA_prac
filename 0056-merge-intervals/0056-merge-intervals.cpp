class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        
        int u = intervals[0][0];
        int v = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++){
            vector<int> in_arr = intervals[i];
            if(in_arr[0] <= v) v = max(v, in_arr[1]);
            else{
                vector<int> temp;
                temp.push_back(u);
                temp.push_back(v);
                res.push_back(temp);
                u = in_arr[0];
                v = in_arr[1];
            }
        }
        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);
        res.push_back(temp);
        return res;
    }
};