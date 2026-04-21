class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int> res(n + m, 0);
        int sum, mul;

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                mul = (num1[i] - '0') * (num2[j] - '0');
                sum = mul + res[i + j + 1];
                res[i + j + 1] = sum % 10;
                res[i + j] += sum/10;
            }
        }

        string st = "";
        for(int num : res){
            if(!(st.empty() && num == 0)){
                st += to_string(num);
            }
        }
        return st.empty() ? "0" : st;
    }
};