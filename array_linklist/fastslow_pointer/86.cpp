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
    ListNode* partition(ListNode* head, int x) {
        //小于list
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        //大于list
        ListNode* dummy1 = new ListNode(-1);
        ListNode* p1 = dummy1;
        // 遍历head
        ListNode* h1 = head;
        while(h1 != NULL){
            if (h1->val < x){
                p->next = h1;
                p = p->next;
            }else{
                p1->next = h1;
                p1 = p1->next;
            }
            // 拼接链表的时候要断干净，防止成环
            ListNode *temp = h1->next;
            h1->next = NULL;
            h1 = temp;
        }
        p->next = dummy1->next;
        return dummy->next;
    }
};