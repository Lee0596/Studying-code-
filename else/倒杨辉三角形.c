#include "stdio.h"
int main()
{
	int n, i, k, a[20][20] = { 1 }, j;
	while ((scanf("%d", &n)) != EOF) {
		n += 1;
		for (i = 1; i <= n; i++) {
			a[1][i] = 1;
			a[i][1] = 1;
		}
		for (i = 3; i <= n; i++) {
			for (k = 2; k <= i; k++) {
				a[i][k] = a[i - 1][k - 1] + a[i - 1][k];
			}
		}
		for (i = n; i >= 1; i--) {
			for (j = 1; j <= n - i && i != 1; j++) {
				printf("   ");
			}
			for (k = 1; k < i; k++) {
				printf("%3d", a[i][k]);
				if (k != i-1 ) {
					printf("   ");
				}
			}
			if (i != 2) {
				printf("\n");
			}
		}
	}
}
