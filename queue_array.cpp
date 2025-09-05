#include<iostream>
using namespace std;

class Queue{
public:
    int arr[5];
    int front;
    int rear;
    int curr;
    Queue(){
        front = -1;
        rear = -1;
        curr = 0;
    }

    void push(int val){
        if(curr == sizeof(arr)/sizeof(arr[0])){
            cout << "Overflow" << endl;
        }
        if(curr == 0){
            front = 0;
            rear = 0;
            arr[rear] = val;
        }
        else{
            rear = (rear + 1) % (sizeof(arr)/sizeof(arr[0]));
        }
            arr[rear] = val;
            curr += 1;
    }

    void pop(){
        if(curr == 0){
            cout << "underflow" << endl;
        }
        int ele = arr[front];
        cout << "popped: "<< ele << endl;
        if(curr == 1){
            front = -1;
            rear = -1;
        }
        else{
            front = (front + 1) % (sizeof(arr)/sizeof(arr[0]));
        }
            curr -= 1;
    }

    void top(){
        if(curr == 0){
            cout << "underflow" << endl;
        }
        else{
           cout << arr[front] << endl;
        }
    }
    void display(){
         if (curr == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        for(int i = 0; i < curr; i++){
            cout << arr[(front + i) % (sizeof(arr)/sizeof(arr[0]))] << " ";
        }
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
    q.pop();
    q.display();
    cout << endl;
    q.top();
}