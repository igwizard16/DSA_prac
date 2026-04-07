class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, res = 0;
        unordered_map<char, int> mp;
        for(int right = 0; right < s.size(); right++){
            mp[s[right]]++;
            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                res += s.size() - right;
                mp[s[left]]--;
                left++;
            }
        }
        return res;
    }
};