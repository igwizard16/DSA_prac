class Solution {
public:
    //MATRIX EXPONENTIATION approach
    using ll = long long;
    static const ll MOD = 1000000007;

    struct Matrix{
        ll a, b, c, d;
    };

    Matrix multiply(Matrix A, Matrix B){
        Matrix C;

        C.a = (A.a * B.a  + A.b * B.c) % MOD;
        C.b = (A.a * B.b  + A.b * B.d) % MOD;
        C.c = (A.c * B.a  + A.d * B.c) % MOD;
        C.d = (A.c * B.b  + A.d * B.d) % MOD;

        return C;
    }

    Matrix power(Matrix base, long long n){
        Matrix ans = {1, 0, 0, 1}; //Identity matrix

        while(n > 0){
            if(n & 1) ans = multiply(ans, base);

            base = multiply(base, base);
            n >>= 1;
        }
        return ans;
    }

    int countGoodStrings(long long n) {
        Matrix M = {1, 1, 1, 0};

        Matrix result = power(M, n);
        long long Fn = result.b;

        return (2 * Fn) % MOD;
    }
};