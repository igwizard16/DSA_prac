class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int same_ele = 0;

        //[1,5,6,4,6] -> till idx 3 the target is equal
        while(same_ele < n && nums[same_ele] == target[same_ele]){
            same_ele++;
        }

        vector<int> temp = nums;
        sort(temp.begin() + same_ele, temp.end(), greater<int>());
        if(temp != target) return 0;

        int idx = min(same_ele, n - 1);
        int cnt = 1;
        for(int i = idx; i > 0 && target[i - 1] >= target[i]; i--){
            cnt++;
        }
        return cnt;
    }
};