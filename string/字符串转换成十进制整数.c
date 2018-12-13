#include <stdio.h>
int main( )
{
	char s[100] = { '\n' }, x;
	int i = 0, sum = 0;
	while ((x=getchar( ))!= '#') {	
		if ((x == '-') || (x <= 'F'&&x >= 'A') || (x <= 'f'&&x >= 'a')|| (x <= '9'&&x >= '0')) {
			s[i] = x;
			i++;
		}
	}
	s[i] = '\0';
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == '-') {
			continue;
		}
		if (s[i] <= 'F'&&s[i] >= 'A') {
			sum = sum * 16 + s[i] - 'A' + 10;
		}
		else {
			if (s[i] <= 'f'&&s[i] >= 'a') {
				sum = sum * 16 + s[i] - 'a' + 10;
			}
			else {
				sum = sum * 16 + s[i] - '0';
			}
		}
	}
	if (s[0] == '-') {
		sum *= -1;
	}
	printf("%d", sum);
	return 0;
}
