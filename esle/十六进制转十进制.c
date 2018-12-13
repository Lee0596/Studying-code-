#include <stdio.h>
#include<string.h>
int prime(int m);
int sum(int m, int n);
	int	main()
	{
		char a[100];
		scanf("%s", a);
		int len = strlen(a), sum = 0, i, b;
		for (i = 0; i < len; i++)
		{
			if (a[i] >= 'a' && a[i] <= 'f')
				b = a[i] - 'a' + 10;
			else if (a[i] >= 'A' && a[i] <= 'F')
				b = a[i] - 'A' + 10;
			else b = a[i] - '0';
			sum += (int)(b * pow(16.0, len - 1 - i));
		}
		printf("%d", sum);
		return 0;
	}
