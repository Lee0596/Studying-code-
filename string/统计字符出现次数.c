#include <stdio.h>
int main( )
{
	char s[100], x, ch;
	int i = 0, cnt = 0;
	while ((x=getchar( ))!= '\n') {			
			s[i] = x;
			i++;
	}
	s[i] = '\0';
	ch = getchar();
	for (i = 0; s[i] != '\0'; i++) {
		if (ch == s[i]) {
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}
