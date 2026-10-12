
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> mpp;
        int rank = 1;

        for (int x : sorted) {
            if (mpp.find(x) == mpp.end()) {
                mpp[x] = rank++;
            }
        }

        vector<int> res;
        for (int x : arr) {
            res.push_back(mpp[x]);
        }
        return res;
    }
};
