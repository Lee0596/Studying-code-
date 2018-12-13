#include<stdio.h>
int main(void)
{
	int i = 0, sum = 0;
	char a[100];
	do {
		a[i] = getchar();
		i++;
	} while (a[i-1] != '\n');
	  a[i] = '\0';
	for (i=0; a[i]!='\0'; i++) {
		if (a[i] >= '0'&&a[i] <= '9') {
			sum = sum * 10 + a[i] - '0';
		}
	}
	printf("%d", sum);
	return 0;
}
