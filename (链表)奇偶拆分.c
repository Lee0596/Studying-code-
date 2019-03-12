#include<stdio.h>
struct List {
	int data;
	struct List *next;
};
int main() {
	struct List *head = (struct List*) malloc(sizeof(struct List)), *tail, *p;
	head->next = NULL;
	tail = head;
	int num;
	while (scanf("%d", &num) != EOF) {
		p = (struct List*) malloc(sizeof(struct List));
		p->data = num;
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	head = head->next;
	struct List *list0 = NULL, *list1 = NULL;
	while (head) {
		tail = head;
		if (head->data % 2 == 0) {
			if (list0 == NULL) {
				list0 = head;
				head = head->next;
				list0->next = NULL;
			}
			else {
				head = head->next;
				tail->next = list0;
				list0 = tail;
			}
		}
		else {
			if (list1 == NULL) {
				list1 = head;
				head = head->next;
				list1->next = NULL;
			}
			else {
				head = head->next;
				tail->next = list1;
				list1 = tail;
			}
		}
	}
	while (list0) {
		printf("%d ", list0->data);
		list0 = list0->next;
	}
	printf("\n");
	while (list1) {
		printf("%d ", list1->data);
		list1 = list1->next;
	}
	return 0;
}
