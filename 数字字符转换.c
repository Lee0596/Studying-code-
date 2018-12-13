#include <stdio.h>
#include <string.h>
int main()
{
	char s[100] = { '\n' }, x;
	int i = 0, sum = 0;
	while ((x = getchar()) != '\n') {
		if (x <= '9'&&x >= '0') {
			s[i] = x;
			i++;
		}
	}
	for (i = 0; s[i] != '\0'; i++) {
		sum = sum * 10 + s[i] - '0';
	}
	printf("%d", sum);
	return 0;
}
