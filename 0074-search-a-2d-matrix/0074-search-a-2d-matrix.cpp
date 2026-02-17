class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int rows = 0;

        while(rows < m){
            int low = 0, high = n - 1;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(matrix[rows][mid] == target){
                    return true;
                }
                if(matrix[rows][mid] < target){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            rows++;
        }
        return false;
    }
};