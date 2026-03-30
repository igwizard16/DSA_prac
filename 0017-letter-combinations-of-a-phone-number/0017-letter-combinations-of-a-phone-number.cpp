class Solution {
public:
    void combination(int idx, string s, string digits, vector<string>& ans, string store[]){

        if(idx == digits.length()){
            ans.push_back(s);
            return;
        }
        int digit = digits[idx] - '0';
        for(int i = 0; i < store[digit].size(); i++){
            combination(idx + 1, s + store[digit][i], digits, ans, store);
        }
    }

    vector<string> letterCombinations(string digits) {
        string store[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string s = "";
        combination(0, s, digits, ans, store);
        return ans;
    }
};