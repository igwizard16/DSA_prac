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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1) return head;
        if(!head || !head -> next) return head;
        
        int size = 0;
        ListNode* temp = head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevgrouptail = &dummy;

        while(temp){
            temp = temp -> next;
            size++;
        }
        temp = head;

        while(size >= k){
            ListNode* currNode = temp;
            ListNode* prev = NULL;
            for(int i = 0; i < k; i++){
                ListNode* nextNode = currNode -> next;
                currNode -> next = prev;
                prev = currNode;
                currNode = nextNode;
            }
            prevgrouptail -> next = prev;
            temp -> next = currNode;
            prevgrouptail = temp;
            temp = currNode;
            size -= k;
        }
        return dummy.next;
    }
};