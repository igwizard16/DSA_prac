class Solution {
public:
    string maskPII(string s) {
        string res = "";

        //email address
        if(s.find('@') != string :: npos){
            s[0] = tolower(s[0]);
            int idx = s.find('@');
            char ch = s[idx - 1];
            ch = tolower(ch);

            res += s[0];
            int x = 5;

            while(x > 0){
                res += '*';
                x--;
            }
            res += ch;
            
            for(int i = idx; i < s.size(); i++){
                res += tolower(s[i]);
            }
            return res;
        }

        //phone number 
        
        string digits = "";
        for(char c : s){
            if(isdigit(c)){
                digits += c;
            }
        }
        
        int n = digits.size();

        string last4 = digits.substr(n - 4);

        if(n == 10){
            return "***-***-" + last4;
        }

        //country code
        string code = "+" + string(n - 10, '*');

        return code + "-***-***-" + last4;
    }
};