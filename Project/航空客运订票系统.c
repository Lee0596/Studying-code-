#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include  <windows.h>  
#include <iostream>
#include <algorithm>
#define MAXSIZE 99999
int booksum=0, waitsum = 0;
typedef struct airplane                             //结构体保存航线信息
{
	char star[20];                                 //起始
	char end[20];                                  //终点
	char airplane[20];                             //航班号
	char num[20];                                  //飞机号
	int  data;                                     //日期
	int  max;                                      //定额
	int remain;                                    //余额	  
	int set[1000] = {};                                 //座位
	struct airplane *next;                         //指向下一个节点
}airplane;
struct
{
	char plane[20];
	char name[20];
	int  data;
	int num;
	char set[100]{};
	int flag = 1;
}book[99999];                                         //客户名单
struct
{
	char plane[20];
	char name[20];
	int  data;
	int num;
	int flag = 1;
}wait[99999];
void menu() {

	printf("******************** 航空客运订票系统 ********************\n");

	printf("*                    1-----新建航线信息                  *\n");

	printf("*                    2-----查询航线信息                  *\n");

	printf("*                    3-----订票业务                      *\n");

	printf("*                    4-----退票业务                      *\n");

	printf("*                    5-----删除航线信息                  *\n");

	printf("*                    6-----添加航线信息                  *\n");

	printf("*                    7-----载入航线信息                  *\n");

	printf("*                    8-----保存航线信息                  *\n");

	printf("*                    9-----航线信息展示                  *\n");

	printf("*                    0-----退出程序                      *\n");

	printf("*请根据编号选择您要进行的操作:");

}
char Judge(char ch) {

	while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n') {

		printf("输入有错误，请重新输Y/N: ");

		scanf(" %c", &ch);

	}

	return ch;

}
int IsNULL(airplane *head) {

	if (head == NULL || head->next == NULL) {

		printf("目前没有信息,请先输入或载入信息\n");           //目前没有职工信息

		system("pause");

		return 1;

	}

	else {

		return 0;

	}

}
airplane *Create(airplane *head)               //创建链表

{

	int count = 0;

	char slect = 'Y';

	airplane *tail, *q;

	head = (airplane *)malloc(sizeof(airplane));

	head->next = NULL;

	q = head;

	while (slect == 'Y' || slect == 'y')            //是否继续录入信息

	{

		system("cls");

		tail = (airplane*)malloc(sizeof(airplane));

		printf("请按以下格式顺序输入航线信息\n");

		printf("起点站名:");

		scanf("%s", &tail->star);

		printf("终点站名:");

		scanf("%s", &tail->end);

		printf("航 班 号:");

		scanf("%s", &tail->airplane);

		printf("飞 机 号:");

		scanf("%s", &tail->num);

		printf("日   期:");

		scanf("%d", &tail->data);

		printf("定  额:");

		scanf("%d", &tail->max);

		printf("余  额:");

		scanf("%d", &tail->remain);

		count++;


		q->next = tail;

		q = tail;

		printf("是否继续录入航线信息Y/N: ");

		scanf(" %c", &slect);

		slect = Judge(slect);

	}

	q->next = NULL;

	printf("航线信息输入完毕,本次共录入 %d 条航线信息\n", count);

	system("pause");

	return head;

}
void Save(airplane *head)                      //保存文件

{

	FILE *fp;

	if (IsNULL(head)) {

		return ;

	}

	if ((fp = fopen("E:\\C++\\text\\airplane.txt", "w")) == NULL)

	{

		printf("文件打开失败\n");             //文件不存在

		system("pause");

		return;

	}

	airplane *p = head->next;

	while (p)

	{

		fprintf(fp, "%s %s %s %s %d %d %d \n", p->star, p->end, p->airplane, p->num, p->data, p->max, p->remain);

		p = p->next;

	}

	fclose(fp);

	printf("航线保存成功!\n");

	system("pause");

	return;

}
void Savebook( int n )                      //保存文件
{
	FILE *fp;
	if ((fp = fopen("E:\\C++\\text\\book.txt", "a")) == NULL)
	{
		printf("文件打开失败\n");             //文件不存在
		system("pause");
		return;
	}
		fprintf(fp, "%s %s %d \n", book[n].plane, book[n].name, book[n].num);
		int i;
		for (i = 0; i < book[n].num; i++) {
			fprintf(fp, "%d ", book[n].set[i]);
		}
		fprintf(fp, "\n");
	fclose(fp);
	printf("订票保存成功!\n");
	system("pause");
	return;
}
void Savewait(int n)                      //保存文件
{
	FILE *fp;
	if ((fp = fopen("E:\\C++\\text\\wait.txt", "a")) == NULL)
	{
		printf("文件打开失败\n");             //文件不存在
		system("pause");
		return;
	}
		fprintf(fp, "%s %s %d %d\n", wait[n].plane, wait[n].name, book[n].data, wait[n].num);
	fclose(fp);
	printf("候补信息保存成功!\n");
	system("pause");
	return;
}
airplane *Load(airplane *head)            //载入信息

{
	FILE *fp;

	if ((fp = fopen("E:\\C++\\text\\airplane.txt", "r")) == NULL)                 //文件不存在

	{
		printf("文件打开失败\n");
		system("pause");
		return head;
	}


	if (feof(fp) == EOF) {

		printf("文件为空,请先输入航线信息\n");                //文件内无航线信息

		system("pause");

		return head;

	}

	head = (airplane*)malloc(sizeof(airplane));

	head->next = NULL;

	airplane *q, *p;

	q = head;

	p = (airplane*)malloc(sizeof(airplane));

	p->next = NULL;

	while (fscanf(fp, " %s %s %s %s %d %d %d", &p->star, &p->end, &p->airplane, &p->num, &p->data, &p->max, &p->remain)!=EOF)

	{

		q->next = p;

		q = p;

		p = (airplane*)malloc(sizeof(airplane));

	}

	q->next = NULL;
	fclose(fp);

	printf("航线信息载入成功!\n");	

	system("pause");

	return head;

}
void list(airplane *head) {
	if (IsNULL(head)) {
		return;
	}
	int flag = 1;
	airplane *p = head->next;

	while (p)

	{

		if (flag == 1) {
			printf("起点 终点航班 飞机号 日期 定额 余额    \n");
		}
		flag++;
		printf("%s     %s     %s     %s     %d     %d     %d \n", p->star, p->end, p->airplane, p->num, p->data, p->max, p->remain);
		p = p->next;


	}
		if (booksum == 0) {
			printf("目前无订票\n");
		}
		else {
			printf("已订票旅客姓名 购票数 座位号   \n");
			for (int i = 0; i < booksum&&book[i].flag==1; i++) {
				printf("%s      %d   ", book[i].name, book[i].num);
				for (int j = 0; j < book[i].num; j++) {
					printf("%d   ", book[i].set[j]);
				}
				printf("\n");
			}
		}
		if (waitsum == 0) {
			printf("目前无等候替补旅客\n");
		}
		else {
			printf("等待替补旅客姓名  所需票量    \n ");
			for (int i = 0; i < waitsum&&wait[i].flag==1; i++) {
				printf("%s     %d    ", wait[i].name, wait[i].num);
				printf("\n");
			}
		}
		system("pause");
}
airplane *Del(airplane *head)                    //删除

{


	int flag = 1;

	if (IsNULL(head)) {

		return head;

	}

	int  data;

	char  confirm;


	airplane *p = head, *q = p->next;

	system("cls");


	printf("输入要清除的截止日期: ");

	scanf("%d", &data);

	while (q)

	{
		if (data > q->data) {

			printf("找到日期为 %d 的航班信息如下: \n", q->data);

			if (flag == 1) {

				printf("起点站名 终点站名 航班号 飞机号 日期  定额 余额   \n");

			}

			flag++;

			printf("%s      %s      %s      %s      %d      %d      %d", q->star, q->end, q->airplane, q->num, q->data, q->max, q->remain);

			printf("请确认删除Y/N: ");

			scanf(" %c", &confirm);

			confirm = Judge(confirm);

			if (confirm == 'Y' || confirm == 'y') {

				p->next = q->next;

				free(q);

				printf("日期为 %d 的航线信息成功删除\n", data);
				break;
			}


		}
		else
		{
			p = q;

			q = q->next;

		}

	}
		if (flag == 1) {

			printf("查无日期早于 %d 的航线\n", data);                          // 找不到

		}

		return head;
}
void Search(airplane *head)                    //查询
{

	int n;

	int flag = 1;

	if (IsNULL(head)) {

		return;

	}

	char star[10], end[10];

	char slect = 'Y';

	while (slect == 'Y' || slect == 'y') {

		airplane *p = head->next;

		system("cls");

		flag = 1;

		printf("输入起点站名和终点站名: \n");

		scanf("%s %s", star, end);


		while (p)

		{

			if (strcmp(star, p->star) == 0 && strcmp(end, p->end) == 0) {
				if (flag == 1) {
					printf("找到 %s 到 %s 的航班信息如下: \n", star, end);
					printf("起点 终点 航班号 飞机号 日期 定额 余额    \n");
				}
				flag++;

				printf("%s    %s    %s    %s    %d    %d    %d \n", star, end, p->airplane, p->num, p->data, p->max, p->remain);
			}

			p = p->next;

		}


		if (flag == 1) {

			printf("查无 %s 到 %s 的航线\n", star, end);                          // 找不到

		}

		printf("是否继续查询Y/N: ");                        // 是否继续查询

		scanf(" %c", &slect);

		if (IsNULL(head)) {

			return;

		}

	}

}
void Book(airplane *head) {
	char plane[20], name[20];
	int count, flag = 1;
	char ch;
	printf("请输入航班号，姓名，及购票数\n");
	scanf("%s    %s    %d", &plane, &name, &count);
	airplane *p = head, *q = p;
	if (IsNULL(head)) {
		return;
	}
	while (p->next)
	{
		if (strcmp(plane, p->airplane) == 0) {
			flag++;
			break;
		}
		q = p;
		p = p->next;
	}
	if (flag == 1) {
		printf("当前无此条航线");
		system("pause");
		return;
	}
	if (p->remain >= count) {
		printf("已成功为您订票！\n");
		strcpy(book[booksum].name, name);
		book[booksum].data=p->data;
		strcpy(book[booksum].plane, p->airplane);
		book[booksum].num = count;
		int j, t;
		for ( t = 0; t < book[booksum].num; t++) {
			for (j = 1; j <= p->max; j++) {
				if (p->set[j] != 0) {
					book[booksum].set[t] = j;
					p->set[j] = 0;
					break;
				}
			}
		}
		Savebook(booksum);
		booksum++;
		p->remain -= count;
	}
	else {
			printf("目前余票不足，是否登记候补?Y/N:\n");
			scanf(" %c", &ch);
			if (ch == 'Y' || ch == 'y') {
				strcpy(wait[waitsum].name, name);
				strcpy(wait[waitsum].plane, p->airplane);
				wait[waitsum].data = p->data;
				wait[waitsum].num = count;
				Savewait(waitsum);
				waitsum++;
			}
			printf("已成功将您加入候补队列！\n");
	}
	
}
void recommend(airplane *head) {
	airplane *p = head, *q = p;
	char plane[20], ch = '1',name[20];
	int count;
	int  data;
	printf("请输入航班号，日期, 姓名\n");
	scanf("%s %d %s", &plane, &data,&name);
	for (int i=0; i < booksum; i++) {
		if (book[i].data==data && strcmp(book[i].name, name) == 0 && strcmp(book[i].plane, plane)==0&&book[i].flag==1) {
			count = book[i].num;
			printf("您确定要将航班号为 %s 的 %d 张票退回？Y/N:\n", plane, count);
			scanf(" %c", &ch);
			if (ch == 'Y' || ch == 'y') {
				book[i].flag = -1;
				while (p->next && (strcmp(plane, p->airplane) != 0))
				{
					q = p;
					p = p->next;
				}
				p->remain += count;
				for (int t = 0; t < count; t++) {
					p->set[book[i].set[t]] = 1;
				}
			}
			printf("票已成功退回！\n");
			break;
		}
	}
	char answer;
	if (ch == 'Y' || ch == 'y') {
		int x = 0;
		for (int i = 0; i < waitsum; i++) {
			if (strcmp(wait[i].plane, plane)==0 && p->remain >= wait[i].num&&wait[waitsum].flag == 1) {
				x++;
				printf("现在 %s 号航线有 %d 张余票，您是第 %d 顺位，是否进行订票？Y/N:\n",plane, p->remain,x);
				scanf(" %c", &answer);
				if (answer == 'Y' || answer == 'y') {	
						strcpy(book[booksum].name, wait[i].name);
						strcpy(book[booksum].plane, wait[i].plane);
						book[booksum].num = wait[i].num;
						int k, j;
						for ( j = 0; j < book[booksum].num; j++) {
							for(k=1;k<=p->max;k++){
								if (p->set[k] != 0) {
									book[booksum].set[j] = k;
									p->set[k] = 0;
									break;
								}
							}						
						}
						wait[i].flag = -1;
						printf("已成功为您订票！\n");
						Savebook(booksum);	
						booksum++;
						p->remain -= wait[i].num;
				}
				else {
					continue;
				}
			}
	    }
	}
}
airplane *Add(airplane *head)                         //追加

{

	if (IsNULL(head)) {

		return head;

	}


	char slect = 'Y', confirm = '#';

	airplane *p = NULL, *q, *t;

	while (slect == 'Y' || slect == 'y') {

		int flag = 0;

		system("cls");

		q = head->next;

		p = (airplane*)malloc(sizeof(airplane));

		printf("请按以下顺序输入航线信息\n");

		printf("起点站名:");

		scanf("%s", &p->star);

		printf("终点站名:");

		scanf("%s", p->end);

		printf("航 班 号:");

		scanf("%s", &p->airplane);

		printf("飞 机 号:");

		scanf("%s", &p->num);

		printf("飞行日期:");

		scanf("%d", &p->data);

		printf("乘员定额:");

		scanf("%d", &p->max);

		printf("余票量:");

		scanf("%d", &p->remain);


		while (q) {

			t = q;
			q = q->next;
		}
		if (flag == 0) {



			t->next = p;



			t = p;



		}



		t->next = NULL;

			if (flag == 0) {

				printf("已添加航班号为 %s 的空运信息\n", p->airplane);

			}

			printf("是否继续添加Y/N: ");                   //是否继续添加

			scanf(" %c", &slect);

			slect = Judge(slect);

		}

	return head;
	}

int main(int argc, char *argv[]) {
	airplane *head = NULL;
	int slect;
	while (1) {
		system("cls");
		menu();
		scanf("%d", &slect);
		switch (slect) {
		case 1: system("cls");
			head = Create(head);
			break;
		case 2:system("cls");
			Search(head);
			break;
		case 3:system("cls");
			Book(head);
			break;
		case 4:system("cls");
			recommend(head);
			break;
		case 5:system("cls");
			head=Del(head);
			break;
		case 6:system("cls");
			head = Add(head);
			break;
		case 7:system("cls");
			head = Load(head);
			break;
		case 8:system("cls");
			Save(head);
			break;
		case 9:system("cls");
			list(head);
			break;
		default:exit(0);
		}
	}
	return 0;
}
