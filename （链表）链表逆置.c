struct ListNode *reverse( struct ListNode *head )
{
    struct ListNode *L=(struct ListNode*)malloc(sizeof(struct ListNode)),*p,*q;
    L->next=NULL;
    p=head;
    while(p)
    {
        q=(struct ListNode*)malloc(sizeof(struct ListNode));
        q->data=p->data;
        q->next=L->next;
        L->next=q;
        p=p->next;
    }
    return L->next;
}
