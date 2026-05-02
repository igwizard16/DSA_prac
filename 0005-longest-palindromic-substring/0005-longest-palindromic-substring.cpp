class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2)  return s;

        int len = 1;
        int s_idx = 0;
        //odd
        for(int i = 0; i < n; i++){
            int left = i, right = i;
            while(left >= 0 && right < n && s[left] == s[right]){
                if(right - left + 1 > len){
                    s_idx = left;
                    len = right - left + 1;
                }
                left--;
                right++;
            }
            //even
            left = i, right = i + 1;
            while(left >= 0 && right < n && s[left] == s[right]){
                if(right - left + 1 > len){
                    s_idx = left;
                    len = right - left + 1;
                }
                left--;
                right++;
            }
        }
        return s.substr(s_idx, len);
    }
};