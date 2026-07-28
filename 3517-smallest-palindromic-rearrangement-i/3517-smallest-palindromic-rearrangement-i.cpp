class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int freq[26] = {0};
        
        //store freq of each char from half of the string
        for(int i = 0; i < n/2; i++){
            freq[s[i] - 'a']++;
        }

        int left = 0;
        int right = n - 1;

        for(int i = 0; i < 26; i++){
            while(freq[i] > 0){
                char c = i + 'a';
                s[left++] = c;
                s[right--] = c;
                freq[i]--;
            }
        }
        return s;
    }
};