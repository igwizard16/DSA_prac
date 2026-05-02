class Solution {
public:
    int expansion(string& s, int left, int right){
        int n = s.size();
        while(left >= 0 && right < n && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2) return s;

        int len = 1;
        int s_idx = 0;

        for(int i = 0; i < n; i++){
            if(2 * (n - i) <= len) break;

            int odd = expansion(s, i, i);
            int even = expansion(s, i, i+1);
            int curr_len = max(odd, even);
            if(curr_len > len){
                len = curr_len;
                s_idx = i - (curr_len - 1)/2;
            }
        }
        return s.substr(s_idx, len);
    }
};