#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud_node {
	int    num;
	char   name[20];
	int    score;
	struct stud_node *next;
};
struct stud_node *head, *tail;
struct stud_node *createlist();
struct stud_node *deletelist(struct stud_node *, int );
int main()
{
	int min_score;
	struct stud_node *p, *head = NULL;
	head = createlist();
	scanf("%d", &min_score);
	head = deletelist(head, min_score);
	for (p = head; p != NULL; p = p->next)
		printf("%d %s %d\n", p->num, p->name, p->score);

	return 0;

}

struct stud_node *createlist()
{
	struct stud_node *p, *head, *tail;
	head = (struct stud_node*)malloc(sizeof(struct stud_node));
	head->next = NULL;
	p = head;
	while (1)
	{
		tail = (struct stud_node*)malloc(sizeof(struct stud_node));
		scanf("%d", &tail->num);
		if (!tail->num) 
			break;
		scanf("%s%d", tail->name, &tail->score);
		p->next = tail;
		p = tail;
		p->next = NULL;
	}
	return head;
}
struct stud_node *deletelist(struct stud_node *head, int min_score) {
	struct stud_node *ptr1, *ptr2;
	while (head != NULL && head->score < min_score)
	{
		ptr2 = head;
		head = head->next;
		free(ptr2);
	}
	if (head == NULL)
		return NULL;
	ptr1 = head;
	ptr2 = head->next;
	while (ptr2 != NULL)
	{
		if (ptr2->score < min_score) {
			ptr1->next = ptr2->next;
			free(ptr2);
		}
		else
			ptr1 = ptr2;
		ptr2 = ptr1->next;
	}
	return head;
}
