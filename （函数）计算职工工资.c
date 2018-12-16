#include<stdio.h>
#include<string.h>
struct work {
	char name[10];
	double money1, money2, money3, money4;
};
int main()
{
	int i, n;
	struct work s1[10000];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %lf %lf %lf", &s1[i].name, &s1[i].money1, &s1[i].money2, &s1[i].money3);
		s1[i].money4 = s1[i].money1 + s1[i].money2 - s1[i].money3;
	}
	for (i = 0; i < n; i++) {
		printf("%s %.2f\n", s1[i].name, s1[i].money4);
	}
	return 0;
}
