class Solution {
public:
        void mergesort(vector<int>& a, vector<int>& b, vector<int>& res){
            int i = 0;
            int j = 0;
            int k = 0;
            while(i < a.size() && j < b.size()){
                if(a[i] < b[j]){
                    res[k++] = a[i++];
                }
                else res[k++] = b[j++];
            }
            while(j < b.size()) res[k++] = b[j++];
            while(i < a.size()) res[k++] = a[i++];
        }
        vector<int> sortArray(vector<int>& nums) {
            int n = nums.size();
            if(n <= 1) return nums;
            int n1 = n / 2;
            int n2 = n - n/2;
            vector<int> a(n1), b(n2);
            for(int i = 0; i < n1; i++){
                a[i] = nums[i];
            }
            for(int i = 0; i < n2; i++){
                b[i] = nums[n1 + i];
            }
            sortArray(a);
            sortArray(b);
            mergesort(a, b, nums);
            return nums;
    }
};