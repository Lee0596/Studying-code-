#include<stdio.h>
int main(void)
{
	int i = 0, index, flag = 0;
	char a[100], goal;
	scanf("%c\n", &goal);
	do {
		a[i] = getchar();
		i++;
	} while (a[i - 1] != '\n');
	a[i] = '\0';
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] == goal) {
			flag = 1;
			index = i;
		}
	}
	if (flag) {
		printf("index = %d", index);
	}
	else {
		printf("Not Found");
	}
	return 0;
}
