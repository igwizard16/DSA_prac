class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string clean = "";

        // Remove '-' and convert to uppercase
        for(char c : s) {
            if(c != '-') {
                clean += toupper(c);
            }
        }

        int n = clean.size();
        if(n == 0)
            return "";

        int first = n % k;

        // If divisible by k, first group has k characters
        if(first == 0)
            first = k;

        string res = "";

        // First group
        for(int i = 0; i < first; i++) {
            res += clean[i];
        }

        // Remaining groups
        for(int i = first; i < n; i++) {
            if((i - first) % k == 0)
                res += '-';

            res += clean[i];
        }
        return res;
    }
};