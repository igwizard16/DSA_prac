class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m < n) return {""};
        
        int left = 0; 
        string res = "";
        string final_ans = "";

        unordered_map<char, int> s_mp;
        unordered_map<char, int> t_mp;

        //storing character's freqeuncies from string t
        for(int i = 0; i < n; i++){
            t_mp[t[i]]++;
        }
        
        int need = t_mp.size();
        int have = 0;
        int start = 0, min_len = INT_MAX;

        for(int right = 0; right < m; right++){
            s_mp[s[right]]++;
        
            if(t_mp.count(s[right]) && s_mp[s[right]] == t_mp[s[right]]){
                have++;
            }

            while(have == need){
                if(right - left + 1 < min_len){
                    min_len = right - left + 1;
                    start = left;
                }
                if(t_mp.count(s[left]) && s_mp[s[left]] - 1 < t_mp[s[left]]){
                    have--;
                }
                s_mp[s[left]]--;
                left++;
                final_ans = res;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};