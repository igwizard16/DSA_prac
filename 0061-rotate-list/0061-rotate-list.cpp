/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head -> next || k == 0) return head;

        ListNode* tail = head;
        int size = 1;
        while(tail -> next){
            tail = tail -> next;
            size++;
        }

        k = k % size;
        if(k == 0) return head;

        tail -> next = head;

        int tail_num = size - k;
        ListNode* newtail = head;

        while(--tail_num){
            newtail = newtail -> next;
        }

        ListNode* newhead = newtail -> next;
        newtail -> next = NULL;

        return newhead;
    }
};