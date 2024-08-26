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
        ListNode* hdummy = new ListNode(-1);
        hdummy->next = head;
        ListNode* slow = hdummy;
        ListNode* fast = hdummy;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n + 1; ++i) {
            if (!fast)
                return head; // n is greater than or equal to the length of the list
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Now slow points to the (n+1)th node from the end
        // Remove the nth node
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        ListNode* result = hdummy->next;
        delete hdummy;
        return result;
    }
};
