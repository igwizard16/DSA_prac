class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int i = s.size() - 1;

        while(i >= 0){
            // skip spaces
            while(i >= 0 && s[i] == ' ') i--;

            if(i < 0) break;

            int j = i;

            // find word start
            while(j >= 0 && s[j] != ' ') j--;

            // add space if needed
            if(!res.empty()) res += " ";

            // append word
            res += s.substr(j + 1, i - j);

            i = j;
        }

        return res;
    }
};