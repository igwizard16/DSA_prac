class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.size();
        vector<vector<string>> ans;
        
        int i = 0;
        while(i < n){
            if(s1[i] == s2[i]){
                i++;
                continue;
            }
            else{
                int start = i;
                while(i < n && s1[i] != s2[i]) i++;

                int len = i - start;
                string a = s1.substr(start, len);
                string b = s2.substr(start, len);
                ans.push_back({a, b});
            }
        }
        return ans;
    }
};