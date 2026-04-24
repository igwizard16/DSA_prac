class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int area = 0;
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
                int mid = heights[st.top()];
                st.pop();
                int PSE = st.empty() ? -1 : st.top();
                int NSE = i;
                int width = NSE - PSE - 1;
                area = max(area, width * mid);
            }
            st.push(i);
        }
        return area;
    }
};