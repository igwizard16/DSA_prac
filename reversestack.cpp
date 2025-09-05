//reverse a stack
#include<iostream>
#include<stack>
using namespace std;

//10 20 30 40 50

void print(stack<int>& st){
    stack<int> temp;
    while(st.size() > 0){
        temp.push(st.top());
        st.pop();
}
    while(temp.size() > 0){
        cout << temp.top() << " ";
        st.push(temp.top());
        temp.pop();
    }
}

void pushatbottom(stack<int>& st, int val){
    stack<int> temp;
    while(st.size() > 0){
        temp.push(st.top());
        st.pop();
    }

    st.push(val);

    while(temp.size() > 0){
        st.push(temp.top());
        temp.pop();
    }
}


int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    print(st);
    cout << endl;
    pushatbottom(st, 34);
    print(st);
    
}