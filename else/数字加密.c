#include<stdio.h>
int main(void)
{
	int n, i, a[100], b[100], temp;
	scanf("%d", &n);
	for (i = 1; i <= 4; i++) {
		b[i] = n % 10;
		n /= 10;
	}
	for (i = 1; i <= 4; i++) {
		b[i] += 9;
		b[i] %= 10;
	}
	temp = b[4];
	b[4] = b[2];
	b[2] = temp;
	temp = b[3];
	b[3] = b[1];
	b[1] = temp;
	printf("The encrypted number is ");
	for (i = 4; i >= 1; i--) {
		printf("%d", b[i]);
	}
	return 0;
}
