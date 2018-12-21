#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
int main() {
	FILE *fp1,*fp2;
	char ch;
	if ((fp1 = fopen("E:\\C++\\text\\sysuser.txt", "r")) == NULL) {
		printf("File open error!\n");
		exit(0);
	}
	if ((fp2 = fopen("E:\\C++\\text\\sysuser backups .txt", "w")) == NULL) {
		printf("File open error!\n");
		exit(0);
	}
	while (!feof(fp1)) {
		ch = fgetc(fp1);
		if (ch != EOF) {
			fputc(ch, fp2);
		}
	}
	if (fclose(fp1)) {
		printf("Can not close the file!\n");
		exit(0);
	}
	if (fclose(fp2)) {
		printf("Can not close the file!\n");
		exit(0);
	}
	return 0;
}
