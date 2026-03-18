class Solution {
public:
    void generate(int n, string res, vector<string>& ans){
        if(res.length() == n){
            ans.push_back(res);
            return;
        }
        //add '1', always valid
        generate(n, res + '1', ans);
        //add '0', if the prev one is not '0'
        if(res.empty() || res.back() != '0'){
            generate(n, res + '0', ans);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        generate(n, "", ans);
        return ans;
    }
};