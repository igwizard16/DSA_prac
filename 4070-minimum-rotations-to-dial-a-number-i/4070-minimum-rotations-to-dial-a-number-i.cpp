class Solution {
public:
    int minRotations(string s) {
        int n = s.size();
        int rotations = 0;
        int curr = 0;

        for(char c : s){
            int x = c - '0' ;
            rotations += min(abs(curr - x), 10 - abs(curr - x));
            curr = x;
        }
        return rotations;
    }
};