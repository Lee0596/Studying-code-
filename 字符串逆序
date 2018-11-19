#include <stdio.h>
#include <string.h>
int main() {
	char a[100], temp;
	int i;
	gets(a);
	for (i = 0; i < strlen(a) / 2; i++) {
		temp = a[i];
		a[i] = a[strlen(a) - 1 - i];
		a[strlen(a) - 1 - i] = temp;
	}
	printf("%s", a);

	return 0;
}
