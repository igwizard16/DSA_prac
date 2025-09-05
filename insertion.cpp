#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int v){
        data = v;
        next = NULL;
    }
};

class singleLL {
public:
    Node* head;
    singleLL() {
        head = NULL;
    }

    void at_beg(int x){
        Node* newNode = new Node(x);
        newNode -> next = head;
        head = newNode;
    }   
};

int main(){
    singleLL ob;
    ob.at_beg(3);
    ob.at_beg(4);
    ob.at_beg(5);
    cout <<  "head value: " << ob.head-> data << endl;
    return 0;
}