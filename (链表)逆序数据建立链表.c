#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ListNode {
	int data;
	struct ListNode *next;
};
struct ListNode *createlist();
int main()
{
	struct ListNode *p, *head = NULL;
	head = createlist();
	for (p = head; p != NULL; p = p->next)
		printf("%d ", p->data);
	printf("\n");
	return 0;
}

struct ListNode *createlist() {
	struct ListNode *p, *head=NULL;
	p = head;
	while (1) {
		p = (struct ListNode*)malloc(sizeof(struct ListNode));
		scanf("%d", &p->data);
		if (p->data==-1)
			break;
		p->next = head;
		head = p;
	}
	return head;
}
