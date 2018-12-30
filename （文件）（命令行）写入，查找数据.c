#include<stdio.h> 
#include<stdlib.h> 
int main(int argc, char *argv[]) {         //命令行参数
	FILE *fp;
	int n, j;
	while (1) {
		printf("1:输入若干个整数，并保存到文件\n");
		printf("2:打开数据文件，并查找指定数\n");
		printf("3:退出程序\n");           //功能菜单
		scanf("%d", &n);            //功能选择
		if(n==1)              //写入数据
		{
			if ((fp = fopen("E:\\C++\\text\\data.dat", "wb")) == NULL) {
				printf("File open error!\n");
				exit(0);
			}
			printf("请输入若干个整数，每个整数间用空格隔开，按^Z结束输入：\n");
			while (~scanf("%d", &j)) {
				fwrite(&j, sizeof(int), 1, fp);
			}
			if (fclose(fp)) {
				printf("Can not close the file!\n");
				exit(0);
			}
			continue;
		}
		if (n == 2)          //查找数据
		{   
			int data, f, flag = 1, i = 1;
			if ((fp = fopen("E:\\C++\\text\\data.dat", "rb")) == NULL) {
				printf("File open error!\n");
				exit(0);
			}
			printf("请输入您要寻找的数：");
			scanf("%d", &f);
			while (!feof(fp)) {
				fread(&data, sizeof(int), 1, fp);
				if (data == f) {
					flag = 0;
					printf("%d位于第%d个数\n", f, i);
				}
				i++;
			}
			if (flag) {                //没有找到指定数据
				printf("NOT FOUND!\n");        
			}
			if (fclose(fp)) {
				printf("Can not close the file!\n");
				exit(0);
			}
			continue;
	    }
		if (n == 3)          //退出程序
		{
			break;
		}
	}


	return 0;
}
