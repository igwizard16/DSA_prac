class Solution {
public:
    int findmax(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++){
            maxi = max(piles[i], maxi);
        }
        return maxi;
    }

    double total_hours(vector<int>& piles, int mid){
        double totalhour = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++){
            totalhour += ceil((double) piles[i] / (double) mid);
        }
        return totalhour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int low = 1;
        int high = findmax(piles);
        
        while(low <= high){
            int mid = (low + high)/2;
            double totalhour = total_hours(piles, mid);
            if(totalhour <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};