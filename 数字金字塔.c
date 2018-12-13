#include <stdio.h>
#include <math.h>
void pyramid( int n );
int main( )
{
	int  n,i,a,b;
	printf("输入行数\n");
	scanf("%d", &n);
	/*for (a = 1; a <= i; a++) {
		b = i - a;
		for (b; b >= 1; b--) {
			printf(" ");
		}
		for (n = 1; n <= (2 * a) - 1; n++) {
			printf("*");
		}
		printf("\n");
	}*/
	pyramid(n);

	return 0;
}

void pyramid(int n) {
	int a=1 , b, c, d = n;
	for (a; a <= d; a++) {
		b = d - a;
		for (b; b >= 1; b--) {
			printf(" ");
		}
		for (c = 1; c <= a; c++) {
			printf("%d ", a);
		}
		printf("\n");
	}
}
