class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);

        for(auto &it : nums){
            freq[it]++;
        }

        vector<int> res;
        int repeated = -1;
        int missing = -1;
        for(int i = 1; i <= n; i++){
            if(freq[i] == 2) repeated = i;
            else if(freq[i] == 0) missing = i;
        }
        res.push_back(repeated);
        res.push_back(missing);
        return res;
    }
};