#include<stdio.h> 
#include<stdlib.h> 
int main() {
	FILE *fp;
	int num;
	char name[30];
	int i, score;
	int avg=0;
	if ((fp = fopen("E:\\C++\\text\\student score.txt", "r")) == NULL) {
		printf("File open error!\n");
		exit(0);
	}
	for (i = 0; i < 5; i++) {
		fscanf(fp, "%d%s%d", &num, &name, &score);
		avg += score;
		printf("%d %s %d\n", num, name, score);
	}
	printf("Average score:%d\n", avg / 5);
	if (fclose(fp)) {
		printf("Can not close the file!\n");
		exit(0);
	}
	return 0;
}
