class Solution {
public:
    long long sumAndMultiply(int n) {

        long long y = 0;
        long long sum = 0;
        int idx = 0;

        while(n > 0){
            int digit = n % 10;
            n = n/10;
            if(digit == 0) continue;

            y += digit * pow(10, idx);
            sum += digit;
            idx++;
        }

        return y * sum;

    }
};