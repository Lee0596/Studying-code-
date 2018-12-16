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
	int i, n;
	struct student s1;
	struct student max;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %s %d %d %d", &s1.num, &s1.name, &s1.score1, &s1.score2, &s1.score3);
		s1.ave = (s1.score1 + s1.score2 + s1.score3) / 3.0;
		if (i == 1)
		max = s1;
		if (max.ave < s1.ave) {
			max = s1;
		}
	}
	printf("num:%d,name:%s,average:%.2f", max.num, max.name, max.ave);
	return 0;
}
