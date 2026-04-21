class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();

        if(k == n) return "0";

        for(int i = 0; i < n; i++){
            while(!st.empty() && k > 0 && st.top() > num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k > 0){
            st.pop();
            k--;
        }

        string res = "";
        
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        int zeroes = 0;
        while(zeroes < (int)res.size() - 1 && res[zeroes] == '0') zeroes++;
        
        return res.substr(zeroes);
    }
};