class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(101, 0);
        vector<int> res;
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }
        for(int i = mini; i < maxi; i++){
            if(freq[i] == 0) res.push_back(i); 
        }
        return res;
    }
};