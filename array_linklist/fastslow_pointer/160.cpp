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
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(p1 != p2){
            if (p1 == NULL){
                p1 = headB;
            }else{
                p1 = p1->next;
            }
            if (p2 == NULL){
                p2 = headA;
            }else{
                p2 = p2->next;
            }
        }
        return p1;
    }
};


// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码不保证正确性，仅供参考。如有疑惑，可以参照我写的 java 代码对比查看。

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int lenA = 0, lenB = 0;
    // 计算两条链表的长度
    for (ListNode *p1 = headA; p1 != nullptr; p1 = p1->next) {
        lenA++;
    }
    for (ListNode *p2 = headB; p2 != nullptr; p2 = p2->next) {
        lenB++;
    }
    // 让 p1 和 p2 到达尾部的距离相同
    ListNode *p1 = headA, *p2 = headB;
    if (lenA > lenB) {
        // p1 先走过 lenA-lenB 步
        for (int i = 0; i < lenA - lenB; i++) {
            p1 = p1->next;
        }
    } else {
        // p2 先走过 lenB-lenA 步
        for (int i = 0; i < lenB - lenA; i++) {
            p2 = p2->next;
        }
    }
    // 看两个指针是否会相同，p1 == p2 时有两种情况：
    // 1、要么是两条链表不相交，他俩同时走到尾部空指针
    // 2、要么是两条链表相交，他俩走到两条链表的相交点
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;  
    }
    return p1;
}
