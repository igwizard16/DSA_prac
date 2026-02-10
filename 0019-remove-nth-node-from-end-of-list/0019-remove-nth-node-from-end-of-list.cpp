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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head -> next) return NULL;
        int size = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp -> next;
            size++;
        }

        if(n == size){
            return head -> next;
        }
        n = size - n;

        temp = head;
        while(--n){
            if(n < 0) break;
            temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        return head;
    }
};