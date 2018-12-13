#include<stdio.h>
int main(void)
{
	int i, j, flag = 1;
	char a[100];
	for (i = 0; a[i-1] != '\n'; i++) {
		a[i] = getchar();
	}
	a[i] = '\0';
	for (i = 0; a[i] != '\0'; i++) {
		putchar(a[i]);
	}
	i -= 2;
	for (j = 0; j <= i; j++, i--) {
		if (a[i] != a[j]) {
			flag = 0;
			break;
		}
	}
	if (flag) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}
