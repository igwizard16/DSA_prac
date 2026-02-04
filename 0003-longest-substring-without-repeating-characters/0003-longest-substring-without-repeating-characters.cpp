class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, -1);
        int left = 0, ans = 0;
//pwwkew
//012345
        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]] >= left) {
                left = freq[s[right]] + 1;
            }
            freq[s[right]] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};