#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include  <windows.h>                                      //预编译头
#define FILE_BUFFER_LENGTH 30000
typedef struct employee                             //结构体保存职工信息
{
	int ID;                                         //ID号
	char name[10];                                  //姓名
	float base;                                     //基本工资
	float salary;                                   //职务工资
	float allowance;                                //津贴
	float insurance;                                //医疗保险
	float fund;                                     //公积金
	float total;                                    //总工资
	struct employee *next;                          //指向下一个节点
}employee;
typedef struct employeelist                         
{
	int ID;
	char name[10];
	float base, salary, allowance, insurance, fund, total;
}employeelist;   //排序时保存信息
struct employee *Funtionmenu(employee *head);       //功能选择
struct employee *Create(employee *head);            //创建链表
void Search(employee *head);                        //查找
struct employee *Change(employee *head);            //修改
struct employee *Del(employee *head);               //删除
struct employee *Add(employee *head);               //追加
void Statistics(employee *head);                    //统计
void Save(employee *head);                          //保存信息
struct employee *Load(employee *head);              //载入信息
struct employee *Quit(employee *head);              //退出菜单
char Judge(char);                                   //Y/N选择错误
void IDbubble(employeelist* , int);                 //按ID号从小到大排序
void Basebubble(employeelist*, int);                //按基本工资从高到低排序
void Salarybubble(employeelist*, int);              //按职务工资从高到低排序
void Allowancdbubble(employeelist*, int);           //按津贴从高到低排序
void Insurancebubble(employeelist*, int);           //按医疗保险从高到低排序
void Fundbubble(employeelist*, int);                //按公积金从高到低排序
void Totalbubble(employeelist*, int);               //按总工资从高到低排序
int IsNULL(employee *head);                         //判断链表是否为空
void DestroyList(employee *head);                   //退出时销毁链表
void menu() {
	printf("******************** 职工工资管理系统 ********************\n");
	printf("*                    1-----输入职工信息                  *\n");
	printf("*                    2-----查询职工信息                  *\n");
	printf("*                    3-----修改职工信息                  *\n");
	printf("*                    4-----删除职工信息                  *\n");
	printf("*                    5-----追加职工信息                  *\n");
	printf("*                    6-----统计职工信息                  *\n");
	printf("*                    7-----载入职工信息                  *\n");
	printf("*                    8-----保存职工信息                  *\n");
	printf("*                    9-----退出程序                      *\n");
	printf("*请根据编号选择您要进行的操作:");
}                                                   //主功能菜单                                                 
void Searchmenu() {
	printf("******************** 查询职工信息 ********************\n");
	printf("*                    1-----按ID号查询                *\n");
	printf("*                    2-----按姓名查询                *\n");
	printf("*                    3-----返回                      *\n");
	printf("*请根据编号选择您要进行的操作:");
}                                                   //查询功能菜单
void Changemenu() {
	printf("******************** 修改职工信息 ********************\n");
	printf("*                    1-----查询ID号修改              *\n");
	printf("*                    2-----查询姓名修改              *\n");
	printf("*                    3-----返回                      *\n");
	printf("*请根据编号选择您要进行的操作:");
}                                                    //修改功能菜单                           
void Delmenu() {
	printf("******************** 删除职工信息 ********************\n");
	printf("*                    1-----查询ID号删除              *\n");
	printf("*                    2-----查询姓名删除              *\n");
	printf("*                    3-----返回                      *\n");
	printf("*请根据编号选择您要进行的操作:");
}                                                     //删除功能菜单
void Addmenu() {
	printf("******************** 添加职工信息 ********************\n");
	printf("*                    1-----输入ID号追加              *\n");
	printf("*                    2-----返回                      *\n");
	printf("*请根据编号选择您要进行的操作:");
}                                                    //追加功能菜单
void Statisticsmenu() {
	printf("**************************** 统计职工信息 ****************************\n");
	printf("*                    1-----对职工信息进行排序                        *\n");
	printf("*                    2-----统计各项工资平均工资及总工资              *\n");
	printf("*                    3-----统计总工资在各个区间人数及所占比例        *\n");
	printf("*                    4-----打印全部职工工资信息表                    *\n");
	printf("*                    5-----返回                                      *\n");
	printf("*请根据编号选择您要进行的操作:");
}                                                    //统计功能菜单
void Sortmenu() {
	printf("******************** 职工信息排序 ********************\n");
	printf("*                    1-----按ID号从小到大            *\n");
	printf("*                    2-----按基本工资从大到小        *\n");
	printf("*                    3-----按职务工资从大到小        *\n");
	printf("*                    4-----按津贴从大到小            *\n");
	printf("*                    5-----按医疗保险从大到小        *\n");
	printf("*                    6-----按公积金从大到小          *\n");
	printf("*                    7-----按总工资从大到小          *\n");
	printf("*                    8-----返回                      *\n");
	printf("*请根据编号选择您要进行的操作:");
}                                                    //排序功能菜单
void quitmenu() {
	printf("****************************退出菜单 ****************************\n");
	printf("*                    1-----确认已保存职工信息并退出             *\n");
	printf("*                    2-----返回                                 *\n");
	printf("*请根据编号选择您要进行的操作:");
}                                                    //退出功能菜单
employee *Funtionmenu(employee *head) {            //主功能菜单
	int n;
	while (1) {
		system("cls");
		menu();
		scanf("%d", &n);
		switch (n) {
		case 1: system("cls");
			head = Create(head);
			break;
		case 2:system("cls");
			Search(head);
			break;
		case 3:system("cls");
			head = Change(head);
			break;
		case 4:system("cls");
			head = Del(head);
			break;
		case 5:system("cls");
			head = Add(head);
			break;
		case 6:system("cls");
			Statistics(head);
			break;
		case 7:system("cls");
			head = Load(head);
			break;
		case 8:system("cls");
			Save(head);
			break;
		case 9:system("cls");
			head = Quit(head);
		}
	}
}             //
employee *Create(employee *head)               //创建链表
{
	if (head != NULL&&head->next!=NULL) {
		printf("已存有职工信息，若要继续添请选择追加职工信息\n");
		system("pause");
		return head;
	}
	int count = 0;
	char slect = 'Y';
	employee *tail, *q;
	head = (employee *)malloc(sizeof(employee));
	head->next = NULL;
	q = head;
	while (slect == 'Y' || slect == 'y')            //是否继续录入信息
	{
		system("cls");
		tail = (employee*)malloc(sizeof(employee));
		printf("请按以下格式顺序输入职工信息\n");
		printf("I      D:");
		scanf("%d", &tail->ID);
		printf("姓    名:");
		scanf("%s", tail->name);
		printf("基本工资:");
		scanf("%f", &tail->base);
		printf("职务工资:");
		scanf("%f", &tail->salary);
		printf("津    贴:");
		scanf("%f", &tail->allowance);
		printf("医疗保险:");
		scanf("%f", &tail->insurance);
		printf("公 积 金:");
		scanf("%f", &tail->fund);
		count++;
		tail->total = tail->base + tail->salary + tail->allowance + tail->insurance + tail->fund;
		q->next = tail;
		q = tail;
		printf("是否继续录入职工信息Y/N: ");
		scanf(" %c", &slect);
		slect = Judge(slect);
	}
	q->next = NULL;
	printf("职工信息输入完毕,本次共录入%d名职工信息\n", count);
	system("pause");
	return head;
}
void Search(employee *head)                   //查询
{
	int n;
	int flag = 1, ID;
	char  name[10];
	if (IsNULL(head)) {
		return head;
	}
	Searchmenu();
	scanf("%d", &n);
	switch (n) {
	case 1:
		break;
	case 2:
		break;
	case 3:return head;                        //返回
		break;
	default:printf("输入有误，请重新选择\n"); system("pause"); system("cls"); Search(head);
		break;
	}
	if (n == 1) {                              //按ID查询
		char slect = 'Y';
		flag = 1;
		while (slect == 'Y' || slect == 'y') {                 // 是否继续查询
			flag = 1;
			employee *p = head->next;
			system("cls");
			printf("请输入要查询职工的ID号: ");
			scanf("%d", &ID);
			while (p) {
				if (p->ID == ID) {
					if (flag == 1) {
						printf("ID        姓名      基本工资  职务工资  津贴      医疗保险  公积金    总工资\n");
					}
					flag++;
					printf("%04d      %-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", p->ID, p->name, p->base, p->salary, p->allowance, p->insurance, p->fund, p->total);
				}
				p = p->next;
			}
			if (flag == 1) {
				printf("查无此ID号为 %04d 的职工\n", ID);             //找不到
			}
			printf("是否继续查询Y/N：");
			scanf(" %c", &slect);
			slect = Judge(slect);
		}
	} 
	if (n == 2) {                                //按姓名查询
		char slect = 'Y';
		flag = 1;
		while (slect == 'Y' || slect == 'y') {                 // 是否继续查询
			flag = 1;
			employee *p = head->next;
			system("cls");
			printf("请输入要查询职工的姓名: ");
			scanf("%s", &name);
			while (p) {
				if (strcmp(name, p->name) == 0) {
					if (flag == 1) {
						printf("ID        姓名      基本工资  职务工资  津贴      医疗保险  公积金    总工资\n");
					}
					flag++;
					printf("%04d      %-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", p->ID, p->name, p->base, p->salary, p->allowance, p->insurance, p->fund, p->total);
				}
				p = p->next;
			}
			if (flag == 1) {
				printf("查无姓名为 %s 的职工\n", name);                //找不到
			}
			printf("是否继续查询Y/N: ");
			scanf(" %c", &slect);
			slect = Judge(slect);
		}
	}
}
employee *Change(employee *head) {                    //修改
	int n;
	int flag = 1, ID;
	char name[10], slect;
	if (IsNULL(head)) {
		return head;
	}
	Changemenu();
	scanf("%d", &n);
	switch (n) {
	case 1:
		break;
	case 2:
		break;
	case 3:return head;                  //返回
		break;
	default:printf("输入有误，请重新选择\n"); system("pause"); system("cls"); Change(head);
		break;
	}
	if (n == 1) {                                 //搜ID修改
		char slect = 'Y', confirm = NULL;
		while (slect == 'Y' || slect == 'y') {            
			flag = 1;
			employee *p = head, temp;
			system("cls");
			printf("请输入要修改职工的ID号: ");
			scanf("%d", &ID);
			while (p) {
				if (p->ID == ID) {
					temp = *p;
					flag++;
					printf("当前ID号为 %04d 的职工信息为\n", temp.ID);
					printf("ID        姓名      基本工资  职务工资  津贴      医疗保险  公积金    总工资\n");
					printf("%04d      %-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", temp.ID, temp.name, temp.base, temp.salary, temp.allowance, temp.insurance, temp.fund, temp.total);
					printf("是否进行修改Y/N: ");
					scanf(" %c", &confirm);
					confirm = Judge(confirm);
					while (confirm == 'Y' || confirm == 'y') {
						printf("请按以下格式顺序输入职工修改的信息\n");
						printf("I      D:");
						scanf("%d", &p->ID);
						printf("姓    名:");
						scanf("%s", p->name);
						printf("基本工资:");
						scanf("%f", &p->base);
						printf("职务工资:");
						scanf("%f", &p->salary);
						printf("津    贴:");
						scanf("%f", &p->allowance);
						printf("医疗保险:");
						scanf("%f", &p->insurance);
						printf("公 积 金:");
						scanf("%f", &p->fund);
						p->total = p->base + p->salary + p->allowance + p->insurance + p->fund;
						printf("修改后姓名为 %s 的职工信息为\n", p->name);
						printf("ID        姓名      基本工资  职务工资  津贴      医疗保险  公积金    总工资\n");
						printf("%04d      %-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", p->ID, p->name, p->base, p->salary, p->allowance, p->insurance, p->fund, p->total);
						break;
					}
				}
				p = p->next;
			}
			if (flag == 1) {
				printf("查无此ID号为 %04d 的职工\n", ID);                //找不到
			}
			printf("是否继续修改Y/N: ");               // 是否继续修改
			getchar();
			scanf(" %c", &slect);
			slect = Judge(slect);
		}
	} 
	if (n == 2) {                                    //搜姓名修改
		char slect = 'Y', confirm = NULL;
		while (slect == 'Y' || slect == 'y') {  
			flag = 1;
			employee *p = head, temp;
			system("cls");
			flag = 1;
			printf("请输入要修改职工的姓名: ");
			scanf("%s", &name);
			while (p) {
				if (strcmp(name, p->name) == 0) {
					temp = *p;
					flag++;
					printf("当前姓名为 %s 的职工信息为\n", temp.name);
					printf("ID        姓名      基本工资  职务工资  津贴      医疗保险  公积金    总工资\n");
					printf("%04d      %-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", temp.ID, temp.name, temp.base, temp.salary, temp.allowance, temp.insurance, temp.fund, temp.total);
					printf("是否进行修改Y/N: ");
					scanf(" %c", &confirm);
					confirm = Judge(confirm);
					while (confirm == 'Y' || confirm == 'y') {
						printf("请按以下格式顺序输入职工修改的信息\n");
						printf("I      D:");
						scanf("%d", &p->ID);
						printf("姓    名:");
						scanf("%s", p->name);
						printf("基本工资:");
						scanf("%f", &p->base);
						printf("职务工资:");
						scanf("%f", &p->salary);
						printf("津    贴:");
						scanf("%f", &p->allowance);
						printf("医疗保险:");
						scanf("%f", &p->insurance);
						printf("公 积 金:");
						scanf("%f", &p->fund);
						p->total = p->base + p->salary + p->allowance + p->insurance + p->fund;
						printf("修改后姓名为 %s 的职工信息为\n", p->name);
						printf("ID        姓名      基本工资  职务工资  津贴      医疗保险  公积金    总工资\n");
						printf("%04d      %-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", p->ID, p->name, p->base, p->salary, p->allowance, p->insurance, p->fund, p->total);
						break;
					}
				}
				p = p->next;
			}
			if (flag == 1) {
				printf("查无姓名为 %s 的职工\n", name);                //找不到
			}
			printf("是否继续修改Y/N: ");                   // 是否继续修改
			scanf(" %c", &slect);
			slect = Judge(slect);
		}
	}
	return head;
}
employee *Del(employee *head)                    //删除
{
	int n;
	int flag = 1;
	if (IsNULL(head)) {
		return head;
	}
	Delmenu();
	scanf("%d", &n);
	switch (n) {
	case 1:
		break;
	case 2:
		break;
	case 3:return head;                   //返回
		break;
	default:printf("输入有误，请重新选择\n"); system("pause"); system("cls");Del(head);
		break;
	}
	if (n == 1) {                                 //按ID删除
		int ID;
		char slect = 'Y', confirm;
		while (slect == 'Y' || slect == 'y') {
			employee *p = head, *q = p;
			system("cls");
			flag = 1;
			printf("输入要删除的职工ID: "); 
			scanf("%d", &ID);
			while (p->next&&ID != p->ID)
			{
				q = p;
				p = p->next;
			}
			if (p->ID == ID) {
				printf("找到ID为 %04d 的职工信息如下: \n", ID);
				if (flag == 1) {
					printf("ID        姓名      基本工资  职务工资  津贴      医疗保险  公积金    总工资\n");
				}
				flag++;
				printf("%04d      %-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", p->ID, p->name, p->base, p->salary, p->allowance, p->insurance, p->fund, p->total);
				printf("请确认删除Y/N: ");
				scanf(" %c", &confirm);
				confirm = Judge(confirm);
				if (confirm == 'Y' || confirm == 'y') {
					q->next = p->next;
					free(p);
					printf("ID号为 %04d 的职工信息成功删除\n", ID);
				}
			}
			if (flag == 1) {
				printf("查无此ID号为 %04d 的职工\n", ID);                          // 找不到
			}
			printf("是否继续删除Y/N: ");                        // 是否继续删除
			scanf(" %c", &slect);
			if (IsNULL(head)) {
				return head;
			}
		}
	}
	if (n == 2) {                                        //按姓名删除
		char slect = 'Y', name[10], confirm;
		while (slect == 'Y' || slect == 'y') {
			employee *p = head, *q = p;
			system("cls");
			flag = 1;
			printf("输入要删除的职工姓名: ");
			scanf("%s", &name);
			while (p->next&&strcmp(name, p->name))
			{
				q = p;
				p = p->next;
			}
			if (strcmp(name, p->name) == 0) {
				printf("找到姓名为 %s 的职工信息如下: \n", name);
				if (flag == 1) {
					printf("ID        姓名      基本工资  职务工资  津贴      医疗保险  公积金    总工资\n");
				}
				flag++;
				printf("%04d      %-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", p->ID, p->name, p->base, p->salary, p->allowance, p->insurance, p->fund, p->total);
				printf("请确认删除Y/N: ");
				scanf(" %c", &confirm);
				confirm = Judge(confirm);
				if (confirm == 'Y' || confirm == 'y') {
					q->next = p->next;
					free(p);
					printf("姓名为 %s 的职工信息成功删除\n", name);
				}
			}
			if (flag == 1) {
				printf("查无此姓名为 %s 的职工\n", name);
			}
			printf("是否继续删除Y/N: ");
			scanf(" %c", &slect);
			slect = Judge(slect);
			if (IsNULL(head)) {
				return head;
			}
		}
	}
	return head;
}                  
employee *Add(employee *head)                         //追加
{
	if (IsNULL(head)) {
		return head;
	}
	int n, ID;
	Addmenu();
	scanf("%d", &n);
	switch (n) {
	case 1:
		break;
	case 2:return head;                 //返回
		break;
	default:printf("输入有误，请重新选择\n"); system("pause"); system("cls"); Add(head);
		break;
	}
	char slect = 'Y', confirm = '#';
	employee *p=NULL, *q, *t;
	while (slect == 'Y' || slect == 'y') {
		int flag = 0;
		system("cls");
		q = head->next;
		p = (employee*)malloc(sizeof(employee));
		printf("请按以下格式顺序输入职工信息\n");
		printf("I      D:");
		scanf("%d", &p->ID);
		printf("姓    名:");
		scanf("%s", p->name);
		printf("基本工资:");
		scanf("%f", &p->base);
		printf("职务工资:");
		scanf("%f", &p->salary);
		printf("津    贴:");
		scanf("%f", &p->allowance);
		printf("医疗保险:");
		scanf("%f", &p->insurance);
		printf("公 积 金:");
		scanf("%f", &p->fund);
		p->total = p->base + p->salary + p->allowance + p->insurance + p->fund;
		ID = p->ID;
		while (q) {
			if (q->ID == p->ID) {
				flag = 1; 
				printf("已经有ID为 %04d 的职工信息如下\n", ID);                  //有重复ID号
				printf("ID        姓名      基本工资  职务工资  津贴      医疗保险  公积金    总工资\n");
				printf("%04d      %-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", q->ID, q->name, q->base, q->salary, q->allowance, q->insurance, q->fund, q->total);
				printf("是否覆盖原有职工信息Y/N: ");                               //是否覆盖重复
				scanf(" %c", &confirm);
				confirm = Judge(confirm);
				if (confirm == 'Y' || confirm == 'y') {
					q->ID = p->ID;
					strcpy(q->name, p->name);
					q->base = p->base;
					q->salary = p->salary;
					q->allowance = p->allowance;
					q->insurance = p->insurance;
					q->fund = p->fund;
					q->total = p->total;
					printf("已覆盖ID为 %04d 的职工信息\n", q->ID);
				}
			}
			t = q;
			q = q->next;
		}
		if (flag == 0) {
			t->next = p;
			t = p;
		}
		t->next = NULL;
		if (flag == 0) {
			printf("已追加ID为 %04d 的职工信息\n", ID);
		}
		printf("是否继续添加Y/N: ");                   //是否继续添加
		scanf(" %c", &slect);
		slect = Judge(slect);
	}
	return head;
}
void Statistics(employee *head)                        //统计
{
	if (IsNULL(head)) {
		return;
	}
	int n, i = 0, temp;
	int total = 0;
	double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, totalsum = 0;
	double count1 = 0, count2 = 0, count3 = 0, count4 = 0;
	//employeelist *list = (employeelist *)malloc(sizeof(employeelist));
	employeelist list[10000];
	employee *q = NULL;
	q = head->next;
	while (q!=NULL) {
		list[i].ID = q->ID;
		strcpy(list[i].name, q->name);
		list[i].base = q->base;
		list[i].salary = q->salary;
		list[i].allowance = q->allowance;
		list[i].insurance = q->insurance;
		list[i].fund = q->fund;
		list[i].total = q->total;
		i++;
		total += 1;
		sum1 += q->base;
		sum2 += q->salary;
		sum3 += q->allowance;
		sum4 += q->insurance;
		sum5 += q->fund;
		totalsum += q->total;
		if (q->total > 3000) {
			count4 += 1;
		}
		else {
			if (q->total > 2000) {
				count3 += 1;
			}
			else {
				if (q->total > 1000) {
					count2 += 1;
				}
				else {
					count1 += 1;
				}
			}
		}
		q = q->next;
	}
	char slect = 'Y';
	while (slect == 'Y' || slect == 'y') {
		system("cls");
		Statisticsmenu();
		scanf("%d", &n);
		switch (n) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:return;                      //返回
			break;
		default:printf("输入有误，请重新选择\n"); system("pause"); Statistics(head);
			break;
		}
		if (n == 1) {
			system("cls");
			int x;
			Sortmenu();
			scanf("%d", &x);
			while (x < 1 || x>8) {
				printf("输入有误，请重新选择\n");
				scanf("%d", &n);
			}
			switch (x) {                   //职工信息排序
			case 1:IDbubble(list, i);
				break;
			case 2:Basebubble(list, i);
				break;
			case 3:Salarybubble(list, i);
				break;
			case 4:Allowancdbubble(list, i);
				break;
			case 5:Insurancebubble(list, i);
				break;
			case 6:Fundbubble(list, i);
				break;
			case 7:Totalbubble(list, i);
				break;
			case 8:
				break;				
			}
			if (x > 1 && x < 8) {
				printf("排序成功！\n");
			}
    	}
		if (n == 2) {
			printf("各项工资平均工资及总工资情况如下: \n");
			printf("平均基本工资  平均职务工资  平均津贴  平均医疗保险  平均公积金  平均总工资\n");
			printf("%-13.2f  %-13.2f %-9.2f %-13.2f %-11.2f%-13.2f\n", sum1 / total, sum2 / total, sum3 / total, sum4 / total, sum5 / total, totalsum / total);
		}
		if (n == 3) {
			printf("总工资在各个区间人数及所占比例情况如下: \n");
			printf("1000以下     %.0f      %.2f%%  \n1000~2000    %.0f      %.2f%%  \n2000~3000    %.0f      %.2f%%  \n3000以上     %.0f      %.2f%%\n", count1, 100 * count1 / total, count2, 100 * count2 / total, count3, 100 * count3 / total, count4, 100 * count4 / total);
		}
		if (n == 4) {
			printf("全部职工工资信息表如下: \n");
			printf("ID        姓名      基本工资  职务工资  津贴      医疗保险  公积金    总工资\n");
			temp = i;
			while (temp--) {
				printf("%04d      %-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", list[temp].ID, list[temp].name, list[temp].base, list[temp].salary, list[temp].allowance, list[temp].insurance, list[temp].fund, list[temp].total);
			}
			printf("当前共有 %d 条职工信息记录\n", total);
		}
		printf("是否继续统计职工信息Y/N:");                //是否继续统计
		scanf(" %c", &slect);
		slect = Judge(slect);
	}
}
void Save(employee *head)                      //保存文件
{
	FILE *fp;
	if (IsNULL(head)) {
		return head;
	}
	if ((fp = fopen("E:\\C++\\text\\employee.txt", "w")) == NULL)
	{
		printf("文件打开失败\n");             //文件不存在
		system("pause");
		return ;
	}
	employee *p = head->next;
	while (p)
	{
		fprintf(fp, "%04d %s %f %f %f %f %f %f\n", p->ID, p->name, p->base, p->salary, p->allowance, p->insurance, p->fund, p->total);
		p = p->next;
	}
	fclose(fp);
	printf("职工信息保存成功!\n");
	system("pause");
	return;
}
employee *Load(employee *head)            //载入信息
{
	FILE *fp;
	if ((fp = fopen("E:\\C++\\text\\employee.txt", "r")) == NULL)                 //文件不存在
	{
		printf("文件打开失败\n");
		system("pause");
		return head;
	}
	char ch = '0';
	ch = fgetc(fp);
	if (ch == EOF) {
		printf("文件为空,请先输入职工信息\n");                //文件内无职工信息
		system("pause");
		return head;
	}
	head = (employee*)malloc(sizeof(employee));
	head->next = NULL;
	employee *q, *p;
	q = head;
	p = (employee*)malloc(sizeof(employee));
	p->next = NULL;
	while (fscanf(fp, "%d %s %f %f %f %f %f %f", &p->ID, p->name, &p->base, &p->salary, &p->allowance, &p->insurance, &p->fund, &p->total) != EOF)
	{
		q->next = p;
		q = p;
		p = (employee*)malloc(sizeof(employee));
	}
	q->next = NULL;
	fclose(fp);
	printf("职工信息载入成功!\n");
	system("pause");
	return head;
}
employee *Quit(employee *head)                                      //退出菜单
{
	quitmenu();
	int n;
	scanf("%d", &n);
	switch (n) {
	case 1:DestroyList(head);
		break;
	case 2:return head;                 //返回
		break;
	default:printf("输入有误，请重新选择\n"); system("pause"); system("cls"); Quit(head);
		break;
	}
}
char Judge(char ch) {
	while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n') {
		printf("输入有错误，请重新输Y/N: ");
		scanf(" %c", &ch);
	}
	return ch;
}
void IDbubble(employeelist* list, int n) {
	int i, j;
	employeelist t;
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (list[j].ID < list[j + 1].ID) {
				t = list[j];
				list[j] = list[j + 1];
				list[j + 1] = t;
			}
		}
	}
}
void Basebubble(employeelist* list, int n) {
	int i, j;
	employeelist t;
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (list[j].base > list[j + 1].base) {
				t = list[j];
				list[j] = list[j + 1];
				list[j + 1] = t;
			}
		}
	}
}
void Salarybubble(employeelist* list, int n) {
	int i, j;
	employeelist t;
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (list[j].salary > list[j + 1].salary) {
				t = list[j];
				list[j] = list[j + 1];
				list[j + 1] = t;
			}
		}
	}
}
void Allowancdbubble(employeelist* list, int n) {
	int i, j;
	employeelist t;
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (list[j].allowance > list[j + 1].allowance) {
				t = list[j];
				list[j] = list[j + 1];
				list[j + 1] = t;
			}
		}
	}
}
void Insurancebubble(employeelist* list, int n) {
	int i, j;
	employeelist t;
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (list[j].insurance > list[j + 1].insurance) {
				t = list[j];
				list[j] = list[j + 1];
				list[j + 1] = t;
			}
		}
	}
}
void Fundbubble(employeelist* list, int n) {
	int i, j;
	employeelist t;
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (list[j].fund > list[j + 1].fund) {
				t = list[j];
				list[j] = list[j + 1];
				list[j + 1] = t;
			}
		}
	}
}
void Totalbubble(employeelist* list, int n) {
	int i, j;
	employeelist t;
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (list[j].total > list[j + 1].total) {
				t = list[j];
				list[j] = list[j + 1];
				list[j + 1] = t;
			}
		}
	}
}
int IsNULL(employee *head) {
	if (head == NULL || head->next == NULL) {
		printf("目前没有任何职工信息,请先输入职工信息或载入职工信息\n");           //目前没有职工信息
		system("pause");
		return 1;
	}
	else {
		return 0;
	}
}
void DestroyList(employee *head) {
	if (head == NULL || head->next == NULL) {
		exit(0);
	}
	employee *p;
	while (head) {
		p = head->next;
		free(head);
		head = p;
	}
	exit(0);
}
