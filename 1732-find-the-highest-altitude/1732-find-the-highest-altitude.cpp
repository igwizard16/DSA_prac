class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int maxi = 0;
        
        int prefixSum = 0;
        for(int i = 0; i < n; i++){
            prefixSum += gain[i];
            maxi = max(maxi, prefixSum);
        }
        return maxi;
    }
};