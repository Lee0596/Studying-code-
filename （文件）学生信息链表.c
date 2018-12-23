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

void input();

int main()
{
	struct stud_node *p;

	head = tail = NULL;
	input();
	for (p = head; p != NULL; p = p->next)
		printf("%d %s %d\n", p->num, p->name, p->score);

	return 0;
}

void input()
{
	struct stud_node *p;
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
	}
	head = head->next;
}
