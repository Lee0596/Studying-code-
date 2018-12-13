#include<stdio.h>
int main(void)
{
	int i, a[10], flag = 1;
	for(i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 1; i < 10; i++) {
		if (a[i] != 0) {
			printf("%d", i);
			a[i]--;
			break;
		}
	}
	for (i = 0; i < 10; i++) {
		if (a[i] != 0) {
			for (a[i]; a[i] > 0; a[i]--) {
				printf("%d", i);
			}
		}
	}
	return 0;
}
