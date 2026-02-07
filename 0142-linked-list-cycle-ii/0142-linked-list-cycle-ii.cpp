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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        bool cycle = false;

        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                slow = head;
                cycle = true;
                break;
            }
        }

        while(fast && fast -> next){
            if(slow == fast){
                return slow;
                break;
            }
            slow = slow -> next;
            fast = fast -> next;
        }
        if(cycle) return NULL;

        return NULL;
    }
};