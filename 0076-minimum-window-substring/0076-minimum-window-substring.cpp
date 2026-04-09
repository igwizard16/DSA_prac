class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m < n) return {""};
        
        int left = 0; 
        
        int s_mp[128] = {0};
        int t_mp[128] = {0};

        //storing character's freqeuncies from string t
        for(int i = 0; i < n; i++){
            t_mp[t[i]]++;
        }
        
        int need = 0, have = 0;
        int start = 0, min_len = INT_MAX;

        for(int i = 0; i < 128; i++){
            if(t_mp[i] > 0) need++;
        }

        for(int right = 0; right < m; right++){
            s_mp[s[right]]++;
        
            if(t_mp[s[right]] > 0 && s_mp[s[right]] == t_mp[s[right]]){
                have++;
            }

            while(have == need){
                if(right - left + 1 < min_len){
                    min_len = right - left + 1;
                    start = left;
                }
                if(t_mp[s[left]] > 0 && s_mp[s[left]] - 1 < t_mp[s[left]]){
                    have--;
                }
                s_mp[s[left]]--;
                left++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};