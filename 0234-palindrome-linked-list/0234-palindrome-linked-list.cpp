class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        stack<int> st;
        ListNode* temp = head;

        while (temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        int size = st.size() / 2;

        while (size--) {
            if (temp->val != st.top())
                return false;
            st.pop();
            temp = temp->next;
        }

        return true;
    }
};
