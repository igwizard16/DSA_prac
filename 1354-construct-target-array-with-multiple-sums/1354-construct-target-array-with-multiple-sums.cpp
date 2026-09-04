class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;

        for(int it : target){
            pq.push(it);
            sum += it;
        }

        while(true){
            int maxi = pq.top();
            pq.pop();

            if(maxi == 1) return true;

            long long rest = sum - maxi;
            if(rest <= 0 || maxi <= rest) return false;

            long long prev = maxi % rest;
            if(prev == 0){
                if(rest == 1) prev = 1;
                else return false;
            }
            sum = prev + rest;

            pq.push(prev);
        }
    }
};