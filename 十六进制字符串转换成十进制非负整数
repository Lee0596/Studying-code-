#include<stdio.h>
int main(void)
{
	int i = 0, j = 0, sum = 0;
	char a[100], b[100];
	do {
		a[i] = getchar();
		i++;
	} while (a[i-1] != '#');
	  a[i] = '\0';
	for (i=0; a[i]!='\0'; i++) {
		if ((a[i] >= '0'&&a[i] <= '9')||(a[i] >= 'A'&&a[i] <= 'F')||( a[i] >= 'a'&&a[i] <= 'f')) {
			b[j]=a[i];
				j++;
		}
	}
	b[j]='\0';
	for (i = 0; b[i] != '\0'; i++) {
		putchar(b[i]);
		if (b[i] >= '0'&&b[i] <= '9') {
			sum = sum * 16 + b[i] - '0';
		}
		else {
			if (b[i] >= 'A'&&b[i] <= 'F') {
				sum = sum * 16 + b[i] - 'A' + 10;
			}
			else {
				if (b[i] >= 'a'&&b[i] <= 'f') {
					sum = sum * 16 + b[i] - 'a' + 10;
				}
			}
		}
	}
	printf("\n");
	printf("%d", sum);
	return 0;
}
