class Solution {
public:
    bool palindrome_check(string& s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void generate(int idx, string& s, vector<string>& store, vector<vector<string>>& res){
        if(idx == s.size()){
            res.push_back(store);
            return;
        }
        
        for(int i = idx; i < s.size(); i++){
            if(palindrome_check(s, idx, i)){
                store.push_back(s.substr(idx, i - idx + 1));
                generate(i + 1, s, store, res);
                store.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> store;
        vector<vector<string>> res;
        generate(0, s, store, res);
        return res;
    }
};