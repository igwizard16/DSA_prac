class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0};

        for(int student : students) {
            count[student]++;
        }

        for(int i = 0; i < sandwiches.size(); i++) {
            int sandwich = sandwiches[i];
            if(count[sandwich] == 0) {
                return sandwiches.size() - i;
            }
            count[sandwich]--;
        }
        return 0;
    }
};