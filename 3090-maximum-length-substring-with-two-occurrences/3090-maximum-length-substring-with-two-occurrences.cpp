class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26] = {0};
        int left = 0;
        int length = 0;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            while (freq[s[i] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }
            length = max(length, i - left + 1);
        }
        return length;
    }
};