class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++){
            q.push({i, tickets[i]});
        }
        
        int time = 0;

        while(!q.empty()){
            auto[idx, ticket] = q.front();
            q.pop();
            ticket--;
            time++;
            if(ticket == 0 && idx == k) return time;
            if(ticket > 0) q.push({idx, ticket});
        }
        return time;
    }
};