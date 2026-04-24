class Solution {
public:
    int largestrectanglearea(vector<int>& height){
        int n = height.size();
        stack<int> st;
        int area = 0;
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || height[st.top()] >= height[i])){
                int mid = height[st.top()];
                st.pop();
                int PSE = st.empty() ? -1 : st.top();
                int NSE = i;
                int width = NSE - PSE - 1;
                area = max(area, mid * width);
            }
            st.push(i);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m, 0);
        int max_area = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            int area = largestrectanglearea(height);
            max_area = max(max_area, area);
        }
        return max_area;
    }
};