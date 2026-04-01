class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         int basketA = -1, basketB = -1;
        int cntA = 0, cntB = 0;          
        int streak = 0;                   
        int max_len = 0;

        for(int fruit : fruits) {
            if(fruit == basketA) {         
                cntA++;
                streak++;
            } 
            else if(fruit == basketB) {
                swap(basketA, basketB);
                swap(cntA, cntB);
                cntA++;
                streak = 1;                
            } 
            else {                         
                basketB = basketA;
                cntB = streak;           
                basketA = fruit;
                cntA = 1;
                streak = 1;
            }
            max_len = max(max_len, cntA + cntB);
        }
        return max_len;
    }
};