#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
struct sysuser {
	char username[30];
	char password[30];
};
void encrypt(char *);
int main() {
	FILE *fp;
	int i;
	char name[30];
	struct sysuser su;
	if ((fp = fopen("E:\\C++\\text\\sysuser.txt", "w")) == NULL) {
		printf("File open error!\n");
		exit(0);
	}
	for (i = 0; i < 5; i++) {
		printf("Enter %d th sysuser (name password):", i);
		scanf("%s%s", su.username, su.password);
		encrypt(su. password);
		fprintf(fp, "%s %s\n", su.username, su.password);
	}
	if (fclose(fp)) {
		printf("Can not close the file!\n");
		exit(0);
	}
	return 0;
}
void encrypt(char *password) {
	int i;
	for (i = 0; i < strlen(password); i++) {
		password[i] = password[i] ^ 15;
	}
}
