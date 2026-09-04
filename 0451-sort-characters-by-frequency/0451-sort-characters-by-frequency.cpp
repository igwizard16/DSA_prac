class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        vector<pair<char, int>> freq;

        int cnt[256] = {};

        for(char c : s){
            cnt[(unsigned char)c]++;
        }

        for(int i = 0; i < 256; i++){
            if(cnt[i] > 0){
                freq.push_back({(char)i, cnt[i]});
            }
        }

        sort(freq.begin(), freq.end(), [](pair<char, int>& a, pair<char, int>& b){
            return a.second > b.second;
        });

        string res = "";
        
        for(auto [ch, cnt] : freq){
            res += string(cnt, ch);
        }
        return res;
    }
};