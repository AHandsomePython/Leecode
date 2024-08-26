
#include <vector>
#include <iostream>
using namespace::std;

class ListNode {
    public:
        int val;
        ListNode* next;
};

void traverse(ListNode* head) {
    for (ListNode* p = head; p != nullptr; p = p->next) {
        // 迭代访问 p->val
    }
}

void traverse(ListNode* head) {
    // 递归访问 head->val
    traverse(head->next);
}