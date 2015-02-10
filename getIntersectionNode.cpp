/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode* next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sa = 0;
        int sb = 0;
        ListNode* cur = headA;
        if (cur) {sa++; cur=cur->next;}
        
        cur = headB;
        if (cur) {sb++;cur=cur->next;}
        
        if (sa >= sb)
        {
            for(int i = 0; i < sa-sb; i++) headA=headA->next;
        }
        else
        {
            for(int i = 0; i < sb-sa; i++) headB=headB->next;
        }
        
        while(headA && headB)
        {
            if (headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};
