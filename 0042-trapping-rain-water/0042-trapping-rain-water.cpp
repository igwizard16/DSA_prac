class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int left = 0;
        int right = n - 1;
        int total = 0;
        int leftMax = height[left];
        int rightMax = height[right];
        
        while(left < right){
            if(height[left] <= height[right]){
                if(height[left] < leftMax){
                    total += leftMax - height[left];
                }
                else leftMax = height[left];
                left++;
            }
            else{
                if(height[right] <= rightMax){
                    total += rightMax - height[right];
                }
                else rightMax = height[right];
                right--;
            }
        }
        return total;
    }
};