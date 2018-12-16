#include<stdio.h>
#include<string.h>
struct student {
	int num;
	char name[10];
	int score1, score2, score3, total;
};
int main()
{
	long long i, n;
	struct student s1[10000];
	struct student max;
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %s %d %d %d", &s1[i].num, &s1[i].name, &s1[i].score1, &s1[i].score2, &s1[i].score3);
		s1[i].total = s1[i].score1 + s1[i].score2 + s1[i].score3;
		if (i == 1)
			max = s1[i];
		if (max.total < s1[i].total) {
			max = s1[i];
		}
	}
	printf("%s %05d %d", max.name, max.num, max.total);
	return 0;
}
