#include<stdio.h>
int main(void)
{
	int n, x, i, j, b[10] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		do {
			b[x % 10]++;
			x /= 10;
		} while (x != 0);
	}
	int max;
	max = b[0];
	for (i = 0; i <= 9; i++) {
		if (b[i] >= max) {
			max = b[i];
		}
	}
	printf("%d:", max);
	for (i = 0; i <= 9; i++) {
		if (b[i] == max) {
			printf(" %d", i);
		}
	}
	return 0;
}
