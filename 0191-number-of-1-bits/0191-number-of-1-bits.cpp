class Solution {
public:
    int hammingWeight(int n) {
        string s1 = bitset<32>(n).to_string();

        int cnt1 = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == '1') cnt1++;
        }
        return cnt1;
    }
};