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
    ListNode *rotateRight(ListNode *head, int k) {
        if ( head==NULL || head->next==NULL) return head;
        
        int sizeList = 1;
        ListNode* tail= head;
        while(tail->next!=NULL)
        {
            tail = tail->next;
            sizeList++;
        }
        int move = k%sizeList;
        if (move==0) return head;
        
        
        
        ListNode* cur = head;
        tail->next = cur;
        
        for (int i = 0; i < sizeList - move - 1; i++)
        {
            cur = cur->next;
        }
        head = cur ->next;
        cur->next = NULL;
        return cur;
        
    }
};
