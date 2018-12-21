#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
struct sysuser {
	char username[30];
	char password[30];
};
void encrypt(char *);
int checkUserValid(struct sususer *);
int main() {
	struct sysuser su;
	printf("Enter username:");
	scanf("%s", su.username);
	printf("Enter password:");
	scanf("%s", su.password);
	if (checkUserValid(&su) == 1) {
		printf("Valid suer!\n");
	}
	else {
		printf("Invalid user!\n");
	}
	return 0;
}
void encrypt(char *password) {
	int i;
	for (i = 0; i < strlen(password); i++) {
		password[i] = password[i] ^ 15;
	}
}
int checkUserValid(struct sysuser *psu) {
	FILE *fp;
	char usr[30], usr1[30], pwd[30];
	int check = 0;
	strcpy(usr, psu->username);
	strcpy(pwd, psu->password);
	encrypt(pwd);
	strcat(usr, " ");
	strcat(usr, pwd);
	strcat(usr, "\n");
	if ((fp = fopen("E:\\C++\\text\\sysuser.txt", "r")) == NULL) {
		printf("File open error!\n");
		exit(0);
	}
	while (!feof(fp)) {
		fgets(usr1, 30, fp);
		if (strcmp(usr, usr1) == 0) {
			check = 1;
			break;
		}
	}
	if (fclose(fp)) {
		printf("Can not close the file!\n");
		exit(0);
	}
	return check;
}
