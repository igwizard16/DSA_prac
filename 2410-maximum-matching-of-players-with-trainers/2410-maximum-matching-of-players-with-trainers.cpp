class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int p = 0, t = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        while(p < players.size() && t < trainers.size()){
            if(players[p] <= trainers[t]) p++;
            t++;
        }
        return p;
    }
};