#include <stdio.h> 
int main()
{    
	int n;    
	while (scanf("%d", &n)!=EOF)
	{
		for (int i = 31; i >= 0; i--) {
			printf("%d", n >> i & 1);
			if (i % 8 == 0) {
				printf(" ");
			}
		}
		printf("<->%d\n", n);
	}
return 0;
}
