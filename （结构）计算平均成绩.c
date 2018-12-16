#include<stdio.h>
#include<string.h>
struct student {
	int num;
	char name[10];
	int score1;
};
int main()
{
	int i, n, sum=0;
	double ave;
	struct student s1[1000];
	struct student temp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %s %d", &s1[i].num, &s1[i].name, &s1[i].score1);
		sum+= s1[i].score1;
	}
	ave = 1.0*sum / n;
	printf("%.2f\n", ave);
	for (i = 0; i < n; i++) {
		if (s1[i].score1 < ave) {
			printf("%s %05d\n", s1[i].name, s1[i].num);
		}
	}
	return 0;
}
