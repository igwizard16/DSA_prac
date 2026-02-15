class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res = "";
        //sum -> 0 , 1 , 2 = 1 + 1 = 0; carry = 1,
        // 3 = 1 + 1 + 1 = 1 ;carry = 1
        
        while(i >= 0 || j >= 0 || carry != 0){
            int sum = carry;
            if(i >= 0){
                sum += a[i] - '0';
                i--;
            }
            if(j >= 0){
                sum += b[j] - '0';
                j--;
            }
            res += (sum % 2) + '0';
            carry = sum / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};