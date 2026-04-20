class Solution {
public:
    long long subarrayMin(vector<int>& nums){
        stack<int> st;
        int n = nums.size();
        long long sum = 0;

        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || nums[st.top()] >= nums[i])){
                int mid = st.top(); st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                sum += (long long)nums[mid] * (mid - pse) * (nse - mid);
            }
            st.push(i);
        }
        return sum;
    }

    long long subarrayMax(vector<int>& nums){
        stack<int> st;
        int n = nums.size();
        long long sum = 0;

        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || nums[st.top()] <= nums[i])){
                int mid = st.top(); st.pop();
                int pge = st.empty() ? -1 : st.top();
                int nge = i;
                sum += (long long)nums[mid] * (mid - pge) * (nge - mid);
            }
            st.push(i);
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return subarrayMax(nums) - subarrayMin(nums);
    }
};