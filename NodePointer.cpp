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

// void display(Node* head){
//     Node* temp = head;
//     while(temp != NULL){
//         cout << temp -> val << " ";
//         temp = temp -> next;
//     }
//     cout << endl;
// }

int size(Node* head){
    Node* temp = head;
    int n = 0;
    while(temp != NULL){
        n++;
        temp = temp -> next;
    }
    cout << endl;
    return n;
}
void displayrev(Node* head){
    if(head == NULL) return;
    displayrev(head -> next);
    cout << head -> val << " ";
}

void display(Node* head){
    if(head == NULL) return;
    cout << head -> val << " ";
    display(head -> next);
}

void insertAtEnd(Node* head, int val){
    Node* t = new Node(val);
    while (head -> next != NULL) head = head ->next;
        head -> next = t;
    }


int main(){
    Node*a = new Node(10);
    Node*b = new Node(20);
    Node*c = new Node(30);
    Node*d = new Node(40);
    Node*e = new Node(50);
    a -> next = b;
    b -> next = c;
    c -> next = d;
    d->next = e;
    cout << a -> next ->next -> val << endl; //value of c
    // Node* temp = a;
    // while(temp != NULL){
    //     cout << temp->val << " ";
    //     temp = temp -> next;
    // }

    displayrev(a);
    cout << size(a) << endl;
    display(a);
    cout << endl;
    insertAtEnd(a, 30);
    display(a);
    
}