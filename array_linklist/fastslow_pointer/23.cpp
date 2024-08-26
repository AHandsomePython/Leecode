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
    struct MyCompare
    {
        bool operator()(ListNode * a, ListNode * b)
        {
            return a->val > b->val; // a>b返回true
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i;
        if (lists.size()==0){
            return NULL;
        }
        // 虚拟头结点
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        // Min heap
        priority_queue<ListNode*, vector<ListNode*>, MyCompare> pq;
        for (i = 0;i<lists.size();i++){
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        while (!pq.empty()) {
            // 获取最小节点，接到结果链表中
            ListNode* node = pq.top();
            pq.pop();
            p->next = node;
            if (node->next != NULL) {
                pq.push(node->next);
            }
            // p 指针不断前进
            p = p->next;
        }
        return dummy->next;
    }
};