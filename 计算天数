#include<stdio.h> 
int day_of_year(int year, int month, int day);
int main(void)
{
	int year, month, day;
	scanf("%d%d%d", &year, &month, &day);
	printf("%d", day_of_year(year, month, day));
	return 0;
}
int day_of_year(int year, int month, int day) {
	int a[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }, i, sum = 0;
	for (i = 0; i < month; i++) {
		sum += a[i];
	}
	sum += day;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		sum += 1;
	}
	return sum;
}
