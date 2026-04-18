class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        stack<int> st;
        long long sum = 0;

        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || arr[st.top()] >= arr[i])){
                int mid = st.top();
                st.pop();
                int PSE = st.empty() ? -1 : st.top();
                int NSE = i;
                sum = (sum + (long long)arr[mid] * (mid - PSE) % MOD * (NSE - mid) % MOD) % MOD;
            }
            st.push(i);
        }
        return (int)sum;
    }
};