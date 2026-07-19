class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();

        string res;
        vector<bool> vis(26, false);
        vector<int> l_idx(26);

        for(int i = 0; i < n; i++){
            char ch = s[i];
            l_idx[ch - 'a'] = i;
        }

        for(int i = 0; i < n; i++){
            char ch = s[i];
            int idx = ch - 'a';

            if(vis[idx] == true) continue;
            while(res.length() > 0 && res.back() > ch && l_idx[res.back() - 'a'] > i){
                vis[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(ch);
            vis[idx] = true;
        }
        return res;
    }
};