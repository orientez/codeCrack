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
    void mergeList(ListNode *lPtr, ListNode *rPtr)
    {
        // precondition that lPtr and rPtr are not NULL
        ListNode *head = NULL;
        ListNode *cur = NULL;
        if (rPtr->val < lPtr->val) 
        {
            cur = rPtr; 
            head = cur;
            rPtr = rPtr->next;
        }
        else 
        {
            cur = lPtr;
            head = cur;
            lPtr = lPtr->next;
        }
        
        while (lPtr!=NULL and rPtr!=NULL)
        {
            if (rPtr->val < lPtr->val) 
            {
                cur->next = rPtr; 
                cur = cur->next;
                rPtr = rPtr->next;
            }
            else 
            {
                cur->next = lPtr;
                cur = cur->next;
                lPtr = lPtr->next;
            }
            
        }
        
        if (lPtr==NULL)
        {
            cur->next = rPtr;
        }
        if (rPtr==NULL)
        {
            cur->next = lPtr;
        }
        // return the orignal left ptr
        lPtr = head;
    }

    
    
    ListNode *sortList(ListNode *head) {
        if (head==NULL) return NULL;
        if (head->next==NULL) return head;
        
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;

        while (ptr2->next!=NULL && ptr2->next->next!=NULL)
        {
            ptr1 = ptr1 ->next;
            ptr2 = ptr2 ->next ->next;
        }
        
        ListNode *temp = ptr1->next;
        ptr1->next = NULL;
        
        ListNode *right = sortList(temp);
        
        ListNode *left = sortList(head);
        
        mergeList(left, right);
        
        return left;
    }
};
