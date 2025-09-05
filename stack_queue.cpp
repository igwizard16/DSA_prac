#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {

    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        if(!q1.empty()){
        int val =  q1.front();
        q1.pop();
        return val;
        }
        return -1;
    }
    
    int top() {
        if(!q1.empty()){
            return q1.front();
        }
        return -1;
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    cout << "Top: " << st.top() << endl;
    cout << "Pop: " << st.pop() << endl;
    cout << "Empty: " << (st.empty() ? "Yes" : "No") << endl;
}