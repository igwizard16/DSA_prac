class Solution {
public:
    // matrix exponentiation - O(log n)
    /*
    as we know the recurrence - f(n) = f(n - 1) + f(n - 2)
    # what if n is extremely large n = 10^9
    even an O(n) solution would be slow

    So, we can calculate the answer without visiting every stair - using
    MATRIX EXPONENTIATION
    step 1 : convert the recurrence - f(n) = f(n - 1) + f(n - 2) into a matrix
     it uses Binary exponentiation or known as fast power

     * It reduces the number multiplications from O(n) to O(log n)
    */

    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix a, Matrix b) {
        Matrix res(2, vector<long long>(2, 0));

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return res;
    }

    Matrix power(Matrix base, int exp) {
        Matrix res = {{1, 0}, {0, 1}};

        while (exp > 0) {
            if (exp & 1)
                res = multiply(res, base);
            base = multiply(base, base);

            exp >>= 1;
        }
        return res;
    }

    int climbStairs(int n) {
        if (n <= 2)
            return n;

        Matrix M = {{1, 1}, {1, 0}};
        Matrix ans = power(M, n - 2);

        // multiply by [2, 1]
        return ans[0][0] * 2 + ans[0][1];
    }
};