class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = s.size();
        int m = g.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l = 0, r = 0;
        while(l < n && r < m){
            if(g[r] <= s[l]){
                r++;
            }
            l++;
        }
        return r;
    }
};