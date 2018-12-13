#include <stdio.h>
#include <math.h>
int prime(int m);
int main(void)
{
	int i, b = 0;
	for (i = 1; i <= 100; i++) {
		if (prime(i)) {
			printf("%6d", i);
			b++;
		}
		if (b ==10) {
			printf("\n");
			b = 0;
		}
	}
	return 0;
}
int prime(int m) {
	if (m < 2) {
		return 0;
	}
	for (int a = 2; a <= sqrt(m); a++) {
		if (m%a == 0) {
			return 0;
		}
	}
	return 1;
}
