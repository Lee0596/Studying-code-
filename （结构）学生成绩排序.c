#include<stdio.h>
#include<string.h>
struct student {
	int num;
	char name[10];
	int score1, score2, score3;
	double ave;
};
int main()
{
	int i, n, j;
	struct student s1[1000];
	struct student temp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %s %d %d %d", &s1[i].num, &s1[i].name, &s1[i].score1, &s1[i].score2, &s1[i].score3);
		s1[i].ave = (s1[i].score1 + s1[i].score2 + s1[i].score3) / 3.0;
	}
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (s1[j].ave < s1[j + 1].ave) {
				temp = s1[j];
				s1[j] = s1[j + 1];
				s1[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d,%s,%.2f\n", s1[i].num, s1[i].name, s1[i].ave);
	}
	return 0;
}
