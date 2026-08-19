class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;

        int prev_time = 0;
        for(auto &log : logs){
            int x = log.find(':');
            int y = log.find(':', x + 1);

            int id = stoi(log.substr(0, x));
            string type = log.substr(x + 1, y - x - 1);
            int time = stoi(log.substr(y + 1));

            if(type == "start"){
                if(!st.empty()){
                    ans[st.top()] += time - prev_time;
                }
                st.push(id);
                prev_time = time;
            }
            else{
                ans[st.top()] += time - prev_time + 1;
                st.pop();
                prev_time = time + 1;
            }
        }
        return ans;
    }
};