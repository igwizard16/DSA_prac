class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> q;

        for(int student : students){
            q.push(student);
        }

        int i = 0;
        int rotations = 0;

        while(!q.empty() && i < n){
            if(q.front() == sandwiches[i]){
                q.pop();
                i++;
                rotations = 0;
            }
            else{
                q.push(q.front());
                q.pop();
                rotations++;
            }
            if(rotations == q.size()) break;
        }
        return rotations;
    }
};