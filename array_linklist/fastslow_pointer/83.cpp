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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL){
            if(fast->val != slow->val){
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        slow->next = NULL;
        return head;
    }
};