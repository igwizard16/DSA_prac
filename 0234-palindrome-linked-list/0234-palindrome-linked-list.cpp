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

    ListNode* reverseList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* front = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow -> next;
            fast = fast -> next->next;
        }
        ListNode* a = reverseList(slow -> next);
        ListNode* b = head;
        ListNode* temp = a;
        while(a != NULL){
            if(a-> val != b -> val){
                return false;
            }
            a = a -> next;
            b = b -> next;
        }
        slow->next = reverseList(temp);
        return true;
    }
};