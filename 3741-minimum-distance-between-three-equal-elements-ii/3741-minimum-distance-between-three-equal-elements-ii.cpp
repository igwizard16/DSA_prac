class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        
        for(auto& [val, indices] : mp){
            if(indices.size() < 3) continue;
            for(int h = 0; h + 2 < indices.size(); h++){
                ans = min(ans, 2 * (indices[h + 2] - indices[h]));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};