/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    void insertcopybtw(Node* head){
        Node* temp = head;
        while(temp){
            Node* nextElement = temp -> next;
            Node* copy = new Node(temp -> val);
            temp -> next = copy;
            copy -> next = nextElement;
            temp = nextElement;
        }
    }

    void connectRandomPointer(Node* head){
        Node* temp = head;
        while(temp){
            Node* copy = temp -> next;
            if(temp -> random){
                copy -> random = temp -> random -> next;
            }
            else{
                copy -> random = NULL;
            }
            temp = temp -> next -> next;
        }
    }

    Node* getcopy(Node* head){
        Node* temp = head;
        Node* dummynode = new Node(-1);
        Node* res = dummynode;

        while(temp){
            //creating new list
            res -> next = temp -> next;
            res = res -> next;
            //disconnecting and going back to initial state of the LL
            temp -> next = temp -> next -> next;
            temp = temp -> next;
        }
        return dummynode -> next;
    }


    Node* copyRandomList(Node* head) {
        insertcopybtw(head);
        connectRandomPointer(head);
        return getcopy(head);
    }
};