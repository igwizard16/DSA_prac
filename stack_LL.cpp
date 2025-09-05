//implement stack using LL
#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this -> val = val;
        this -> next = NULL;
    }
};


class Linkedlist{
public:
    Node* head;
    Linkedlist(){
        head = NULL;
    }

    void push(int data){
        Node* temp = new Node(data);
        temp -> next = head;
        head = temp;
    }

    void pop(){
        if(head == NULL){
            cout << "stack empty" << endl;
        }
        Node* temp = head;
        head = head -> next;
    }

    int peek(){
        if(head == NULL){
            cout << "stack is empty" << endl;
            return -1;
        }
        else{
            return head -> val;
        }
    }

    bool isEmpty(){
        return head == NULL;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> val << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};
int main(){
    Linkedlist ll;
    ll.push(10);
    ll.push(20);
    ll.push(30);
    ll.push(40);
    ll.push(50);
    ll.display();
    ll.pop();
    ll.pop();
    ll.display();
    cout << ll.peek() << endl;
    cout << ll.isEmpty();

}