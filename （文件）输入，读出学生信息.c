#include<stdio.h> 
#include<stdlib.h> 
int main() {
	struct student {
		int num;
		char name[30], birth[30], class[30];
	};        //创建结构记录信息
	int num;
	char name[30], birth[30], class[30];
	FILE *fp;
	int i, n, j;
	struct student *student = NULL, *temp = NULL;
	while (1) {
		printf("1:写入学生信息\n");
		printf("2:显示学生信息\n");
		printf("3:退出程序\n");    //功能菜单
		scanf("%d", &i);
		if (i == 1)      //写入学生信息
		{
			if ((fp = fopen("E:\\C++\\text\\stu.txt", "w")) == NULL) {
				printf("File open error!\n");
				exit(0);
			}
			printf("您要写入的学生人数；"); 
			scanf("%d", &n);
			student = (struct student*)malloc(sizeof(struct student)*n);
			printf("请在下面输入%d名同学的信息；\n",n);
			for (i = 0; i < n; i++) {
				scanf("%d", &student[i].num);

				scanf("%s", &student[i].name);

				scanf("%s", &student[i].birth);

				scanf("%s", &student[i].class);
			}
			for (i = 1; i < n; i++) {
				for (j = 0; j < n - 1; j++) {
					if (student[j].num > student[j + 1].num) {
						temp = student[j].num;
						student[j].num = student[j + 1].num;
						student[j + 1].num = temp;
					}
				}
			}       //按学号排序
			for (i = 0; i < n; i++) {
				fprintf(fp, "%d %s %s %s\n", student[i].num, student[i].name, student[i].birth, student[i].class);
			}          //写入.tet文件
			free(student);
			if (fclose(fp)) {
				printf("Can not close the file!\n");
				exit(0);
			}
			continue;
		}
		if (i == 2)         //读出学生信息
		{
			if ((fp = fopen("E:\\C++\\text\\stu.txt", "r")) == NULL) {
				printf("File open error!\n");
				exit(0);
			}
			while (!feof(fp)) {
				fscanf(fp, "%d %s %s %s\n", &num, &name, &birth, &class);
				printf("%d %s %s %s\n", num, name, birth,class);
			}
			if (fclose(fp)) {
				printf("Can not close the file!\n");
				exit(0);
			}
			continue;
		}
		if (i == 3)    //退出程序
		{
			break;
		}
	}
	return 0;
}
