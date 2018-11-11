#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	gets(a);
	int len, i, cnt;
	len = strlen(a);
	if (a[0] == ' ')
		cnt = 0;
	else
		cnt = 1;
	for (i = 0; i < len - 1; i++)
	{
		if (a[i] == ' ' && a[i + 1] != ' ')
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
