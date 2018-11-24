#include <stdio.h>
#include <math.h>
int main() {
	char a[100];
	int i, sum = 0;
	gets(a);
	for (i = 0; i < 32; i++) {
		if (a[i]=='1') {
			sum += pow(2, 7 - i % 8);
	    }
		if ((i + 1) % 8 == 0) {
			printf("%d", sum);
			sum = 0;
			if (i != 31) {
				printf(".");
			}
		}
	}
	return 0;
}
