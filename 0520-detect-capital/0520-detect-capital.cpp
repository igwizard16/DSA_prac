class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();

        bool check = true;

        //lower case
        for(char c : word){
            if(c < 'a' || c > 'z'){
                check = false;
                break;
            }
        }

        if(check) return true;

        //all upper case
        bool allUpper = true;
        for(char c : word){
            if(c < 'A' || c > 'Z'){
                allUpper = false;
                break;
            }
        }

        if(allUpper) return true;

        //normal word
        if(word[0] >= 'A' && word[0] <= 'Z'){
            for(int i = 1; i < n; i++){
                if(word[i] < 'a' || word[i] > 'z'){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};