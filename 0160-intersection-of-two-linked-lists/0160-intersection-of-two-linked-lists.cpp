/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempa = headA;
        ListNode* tempb = headB;

        if(headA == NULL || headB == NULL) return NULL;

        while(tempa != tempb){
            if(tempa == NULL){
                tempa = headB;
            }
            else tempa = tempa -> next;
            if(tempb == NULL){
                tempb = headA;
            }
            else tempb = tempb -> next;
        }

        return tempa;
        
    }
};