class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mpp;

        for(int i = 0; i < arr.size(); i++){
            mpp[arr[i]] = i;
        }
        for(int i = 0; i < arr.size(); i++){
            if(mpp.find(2 * arr[i]) != mpp.end() && mpp[2 * arr[i]] != i){
                return true;
            }
        }
        return false;
    }
};