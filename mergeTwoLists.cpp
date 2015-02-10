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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode head(0);
        
        ListNode *mList;
        head.next = mList;
        int v;
        while (l1 && l2)
        {
            
            if (l1->val <= l2->val) 
            {
                v = l1->val;
                l1 = l1->next;
            }
            else
            {
                v = l2->val;
                l2 = l2->next;
            }
            
            ListNode* n = new ListNode(v);
            mList->next = n;
            mList = mList->next;
        }
        
        if (l1) mList = l1; 
        if (l2) mList = l2;
        if (!mList) return NULL;
        
        return head.next->next;
    }
};
