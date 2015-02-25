/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * You are given two linked lists representing two non-negative numbers. 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 8 -> 0 -> 7
 *
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        
        int ll1 = 0;
        int ll2 = 0;
        ListNode *temp = l1;
        while(temp!=NULL) {ll1++; temp=temp->next;}
        temp = l2;
        while(temp!=NULL) {ll2++; temp=temp->next;}
        ListNode *head = NULL;
        ListNode *cur = NULL;
        
        if (ll1>=ll2)
        {
            for (int i = 0 ; i < ll1-ll2; i++)
            {
                ListNode *ptr = new ListNode(l1->val);
                if (head==NULL) {head = ptr; cur = ptr;}
                else cur->next = ptr;
            }
            for (int i = 0; i < ll2; i++)
            {
                ListNode *ptr = new ListNode(l1->val+l2->val);
                if (head==NULL) {head = ptr; cur = ptr;}
                else {cur->next = ptr; cur=cur->next;}          
            }
            
        }
        else
        {
            for (int i = 0 ; i < ll2-ll1; i++)
            {
                ListNode *ptr = new ListNode(l2->val);
                if (head==NULL) {head = ptr; cur = ptr;}
                else cur->next = ptr;
            }
            for (int i = 0; i < ll1; i++)
            {
                ListNode *ptr = new ListNode(l1->val+l2->val);
                if (head==NULL) {head = ptr; cur = ptr;}
                else {cur->next = ptr; cur=cur->next;}
            }
        }
        
        ListNode *ptr9 = NULL;
        
        /*

        */
        //else if (head->val==9)
        
        
        //if (head->next==NULL) return head;
        cur = head;
        while(cur->next!=NULL)
        {
            if (cur->next->val == 9)
            {
                ptr9 = cur->next;
                //ListNode *temp = ptr9->next;
                while (ptr9->val==9)
                {
                    ptr9 = ptr9->next;
                }
                
                if (ptr9->val>=10) 
                {
                    cur->val = cur->val + 1;
                    while(cur!=ptr9)
                    {
                        cur=cur->next;
                        cur->val = 0;
                    }
                }
                else
                {
                    cur=ptr9;
                }
                
                
            }
            else if  (cur->next->val >= 10)
            {
                
                cur->val = cur->val + 1;
                cur->next->val = cur->next->val - 10;
            }
            else
            {
                cur = cur->next;
            }
        }
        
        if (head->val >= 10) 
        {
            ListNode *ptr = new ListNode(1);
            head->val = head->val - 10;
            ptr->next = head;
            head = ptr;
        }
        return head;
         
    }
};
