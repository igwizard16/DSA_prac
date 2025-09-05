//implement queue using LL

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

class LinkedList{
public:
    Node* head;
    Node* tail;
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    void push(int data){
        Node* temp = new Node(data);
        if(tail == NULL) head = tail = temp;
        tail -> next = temp;
        tail = temp;
    }

    void pop(){
        if(head == NULL){
            cout << "queue is empty" << endl;
        }
        head = head -> next;
        if(head == NULL){
            tail == NULL;
        }
    }

    int peek(){
        if(head == NULL){
            cout << "queue is empty" << endl;
            return -1;
        }
        return head -> val;
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
    LinkedList ll;
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