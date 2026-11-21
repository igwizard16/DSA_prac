class Solution {
public:
    bool isVowel(char c) {
        char ch = tolower(c);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }

    string reverseVowels(string s) {
        int n = s.length();

        int left = 0;
        int right = n - 1;
        while (left < right) {
            char ch_l = s[left];
            char ch_r = s[right];

            if (isVowel(ch_l) && isVowel(ch_r)) {
                swap(s[left++], s[right--]);
            } else if (!isVowel(ch_l))
                left++;
            else if (!isVowel(ch_r))
                right--;
        }
        return s;
    }
};