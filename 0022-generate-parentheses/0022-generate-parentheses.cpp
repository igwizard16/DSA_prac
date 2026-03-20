class Solution {
public:
    void generate(int n, string str, vector<string>& res, int open, int close){
        if(str.size() == 2 * n){
            res.push_back(str);
            return;
        }
        if(open < n){
            generate(n, str + '(', res, open + 1, close);
        }
        if(close < open){
            generate(n, str + ')', res, open, close + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> res;
        generate(n, str, res, 0, 0);
        return res;
    }
};