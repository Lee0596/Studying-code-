#include<stdio.h>
#include<string.h>
struct list {
	char name[100], num[100];
	int birth;
};
int main()
{
	int i, n, j;
	struct list s1[10000], temp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %d %s", &s1[i].name, &s1[i].birth, &s1[i].num);
	}
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (s1[j].birth > s1[j + 1].birth) {
				temp = s1[j];
				s1[j] = s1[j + 1];
				s1[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%s %d %s\n", s1[i].name, s1[i].birth, s1[i].num);
	}
	return 0;
}
