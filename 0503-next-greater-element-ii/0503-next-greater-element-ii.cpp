class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n);

        for(int i = 2 * n - 1; i >= 0; i--){
            int idx = i % n;
            int currele = nums[idx];
            while(!st.empty() && st.top() <= currele){
                st.pop();
            }
            if(i < n){
                if(st.empty()){
                    res[i] = -1;
                }
                else res[i] = st.top();
            }
            st.push(currele);
        }
        return res;
    }
};