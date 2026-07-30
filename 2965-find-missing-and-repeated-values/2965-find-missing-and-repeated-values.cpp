class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;
        
        vector<int> freq(N + 1, 0);

        for(auto &it : grid){
            for(int num : it){
                freq[num]++;
            }
        }
        int repeated = -1, missing = -1;

        for(int i = 1; i <= N; i++){
            if(freq[i] == 2) repeated = i;
            else if(freq[i] == 0) missing = i;
        }
        return {repeated, missing};
    }
};