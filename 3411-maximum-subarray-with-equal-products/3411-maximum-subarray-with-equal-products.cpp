
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for(int i = 0; i < n; i++) {
            bool seen[11] = {false};
            bool ok = true;

            for(int j = i; j < n; j++) {

                // If a conflict already exists, no longer
                // subarray starting at i can be valid.
                if(j - i >= 2 && !ok) break;

                int x = nums[j];
                for(int p = 2; p <= x; p++) {
                    if(x % p == 0) {
                        if(seen[p]) ok = false;
                        seen[p] = true;
                        while(x % p == 0) x /= p;
                    }
                }

                // Length 1 and 2 are always valid.
                // Length >= 3 requires pairwise coprimality.
                if(j - i < 2 || ok) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};