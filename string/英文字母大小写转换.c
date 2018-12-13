#include <stdio.h>
#include <math.h>
#include<string.h>
int	main()
{
	char ch[1000];
	int	i, flag = 0;
	while (scanf("%s", &ch) != EOF) {
		if (flag) {
			printf("\n");
		}
		flag++;
		for (i = 0; ch[i] != '\0'; i++) {
			if (ch[i] >= 'A'&&ch[i] <= 'Z') {
				printf("%c", ch[i] - 'A' + 'a');
			}
			else {
				if (ch[i] >= 'a'&&ch[i] <= 'z') {
					printf("%c", ch[i] - 'a' + 'A');
				}
				else {
					printf("%c", ch[i]);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
