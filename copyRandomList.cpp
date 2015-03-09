

struct RandomListNode {
   int label;
   RandomListNode *next, *random;
   RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
   /*
    * a1 -> b1 -> c1 ->
    *  |     |     |
    * a2 -> b2 -> c2 ->
    *
    */
    if (head==NULL) return NULL;
    RandomListNode *newHead = new RandomListNode(head->label);
    RandomListNode *newCur = newHead;
    RandomListNode *cur = head->next;
    head->next = newHead;
    while(cur)
    {
        RandomListNode *temp = new RandomListNode(cur->label);
        cur=cur->next;
        cur->next = temp;
        newCur->next = temp;
        newCur = newCur->next;
    }
    cur = head;
    
    while (cur)
    {
        if (cur->random)
            cur->next->random = cur->random->next;
        cur=cur->next;
    }
    return newHead;
}
