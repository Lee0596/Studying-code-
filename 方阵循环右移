#include<stdio.h> 
int main(void)
{
	int m, n = 0, a[10][10], i = 0, x = 0, c = 0;
	int b[10][10];
	scanf("%d %d", &m,&n);
	for (i = 0; i < n; i++) {
		for (x = 0; x < n; x++) {
			scanf("%d", &a[i][x]);
		}
	}
	m %= n;
	for (i = 0; i < n; i++) {
		for (x = 0; x < n; x++) {
			printf("%d ", a[i][(x + n - m) % n]);
		}
		printf("\n");
	}
	return 0;
}
