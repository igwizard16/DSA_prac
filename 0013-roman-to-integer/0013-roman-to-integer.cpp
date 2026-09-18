class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            int digit = 0;
            int next = 0;

            if(s[i] == 'I'){
                digit = 1;
            }
            if(s[i] == 'V'){
                digit = 5;
            }
            if(s[i] == 'X'){
                digit = 10;
            }
            if(s[i] == 'L'){
                digit = 50;
            }
            if(s[i] == 'C'){
                digit = 100;
            }
            if(s[i] == 'D'){
                digit = 500;
            }
            if(s[i] == 'M'){
                digit = 1000;
            }

            if(i + 1 < s.size()){
                if(s[i + 1] == 'I') next = 1;
                if(s[i + 1] == 'V') next = 5;
                if(s[i + 1] == 'X') next = 10;
                if(s[i + 1] == 'L') next = 50;
                if(s[i + 1] == 'C') next = 100;
                if(s[i + 1] == 'D') next = 500;
                if(s[i + 1] == 'M') next = 1000;
            }

            if(digit < next){
                ans -= digit;
            }
            else ans += digit;
        }
        return ans;
    }
};