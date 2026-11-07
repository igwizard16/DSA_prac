class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        long long cnt = 0;

        int a = -1;
        int b = -1;
        int c = -1;
        
        for(int i = 0; i < n; i++){
            if(s[i] == 'a') a = i;
            else if(s[i] == 'b') b = a;
            else if(s[i] == 'c') c = b;
            
            cnt += i - c;
        }
        return cnt;
    }
};