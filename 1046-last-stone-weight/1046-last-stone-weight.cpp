class Solution {
public:
    void find_stones(vector<int>& stones, int& maxi, int& sec_largest, int& idx_1, int& idx_2){
        int n = stones.size();
        maxi = -1;
        sec_largest = -1;
        idx_1 = -1;
        idx_2 = -1;
        for(int i = 0; i < n; i++){
            if(stones[i] >= maxi) {
                maxi = stones[i];
                idx_1 = i;
            }
        }

        for(int i = 0; i < n; i++){
            if(i != idx_1 && stones[i] >= sec_largest) {
                sec_largest = stones[i];
                idx_2 = i;
            }
        }
    }

    int lastStoneWeight(vector<int>& stones) {
        int maxi, sec_largest;
        int idx_1, idx_2;
        int n = stones.size();

        while(stones.size() > 1){
            find_stones(stones, maxi, sec_largest, idx_1, idx_2);
        
            if(sec_largest == maxi){
                if(idx_1 > idx_2){
                    stones.erase(stones.begin() + idx_1);
                    stones.erase(stones.begin() + idx_2);
                }
                else{
                    stones.erase(stones.begin() + idx_2);
                    stones.erase(stones.begin() + idx_1);
                }
            }
            else{
                int new_weight = maxi - sec_largest;
                if(idx_1 > idx_2) {
                    stones.erase(stones.begin() + idx_1);
                    stones.erase(stones.begin() + idx_2);
                }
                else {
                    stones.erase(stones.begin() + idx_2);
                    stones.erase(stones.begin() + idx_1);
                }
                stones.push_back(new_weight);
            }
        }
        if(stones.empty()) return 0;
        return stones[0];
    }
};