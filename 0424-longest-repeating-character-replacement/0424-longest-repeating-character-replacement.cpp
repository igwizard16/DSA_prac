class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        unordered_map<char, int> mp;
        int max_len = 0, max_freq = 0;
        
        for(int right = 0; right < s.size(); right++){
            mp[s[right]]++;
            max_freq = max(max_freq, mp[s[right]]);
            if((right - left + 1) - max_freq > k){
                mp[s[left]]--;
                left++;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};