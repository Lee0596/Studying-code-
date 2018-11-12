#include <stdio.h> 
int main()
{    
	long  n, x;
	scanf("%ld %ld", &n,&x);
	long a[100], i, flag = 1;
	for (i = 0; i < n; i++) {
		scanf("%ld", &a[i]);
	}
	for (i = 0; i < n; i++) {
		if (a[i] == x) {
			printf("%d", i);
			flag = 0;
			break;
		}
	}
	if (flag) {
		printf("Not Found");
	}
	
  return 0;
}
