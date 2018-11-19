#include<stdio.h>
int main(void)
{
	int i=0, count = 0;
	char a[100];
	do {
		a[i] = getchar();
		i++;
	} while (a[i-1] != '\n');
	i -= 1;
	a[i] = '\0';
	for (i; i >= 0; i--) {
		if (a[i] >= '0'&&a[i] <= '9') {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}
