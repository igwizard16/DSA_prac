class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<pair<int, int>> curr;
        
        int prev_time = 0;

        for(auto &s : logs){
            int id = stoi(s.substr(0, s.find(':')));
            int time = stoi(s.substr(s.rfind(':') + 1));

            if(s.find('e') != -1){
                ans[id] += time - prev_time + 1;
                curr.pop();
                prev_time = time + 1;
            }
            else{
                if(!curr.empty()){
                    ans[curr.top().first] += (time - prev_time);
                }
                curr.push({id, time});
                prev_time = time;
            }
        }
        return ans;
    }
};