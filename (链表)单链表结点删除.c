struct ListNode *readlist()
{
	int data;
	struct ListNode *head = NULL;
	struct ListNode *p;
	while (scanf("%d", &data) && data != -1)
	{
		struct ListNode *q = (struct ListNode*)malloc(sizeof(struct ListNode));
		if (q != NULL)
		{
			q->data = data;
			q->next = NULL;
		}
		else exit(1); 
		if (head != NULL)
		{
			p->next = q; 
		}
		else head = q; 
		p = q;      
	}
	return head;  
}
struct ListNode *deletem( struct ListNode *L, int m ){
    struct ListNode *h,*p,*q;
    h=L;
    while(h->data==m){
        p=h->next;
        free(h);
        h=p;
        if(h==NULL){
          exit(0);
        }
    } 
    p=h;
    q=p->next;
    while(q){
        if(q->data==m){
            p->next=q->next;
            free(q);
            q=p->next;
            continue;
        }
        else{
            p=q;
            q=q->next;
        }
    }

    return h; 
}
