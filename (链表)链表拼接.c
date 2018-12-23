#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ListNode {
	int data;
	struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
void printlist(struct ListNode *head)
{
	struct ListNode *p = head;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	struct ListNode  *list1, *list2;

	list1 = createlist();
	list2 = createlist();
	list1 = mergelists(list1, list2);
	printlist(list1);

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

struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2)
{
	int a[100], n = 0;
	struct ListNode *p;
	p = list1;
	while (p)
	{
		a[n++] = p->data;
		p = p->next;
	}
	p = list2;
	while (p)
	{
		a[n++] = p->data;
		p = p->next;
	}
	int i, j;
	for (j = 0; j < n - 1; j++)
	{
		for (i = 0; i < n - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				int t = a[i]; a[i] = a[i + 1]; a[i + 1] = t;
			}
		}
	}
	struct ListNode *head, *tail;
	struct ListNode *p1;
	head = NULL;
	for (i = 0; i < n; i++)
	{
		p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
		p1->data = a[i];
		p1->next = NULL;
		if (i == 0)
		{
			head = p1;
			head->next = NULL;
		}
		else
		{
			tail->next = p1;
		}
		tail = p1;
		tail->next = NULL;
	}
	return head;
}
