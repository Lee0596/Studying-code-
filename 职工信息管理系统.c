#include"标头.h"
int main(int argc, char *argv[]) {       
	employee *head = NULL;
	system("color 0C");
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
	return 0;
}
struct employee *Create(employee *head)        //创建链表
{
	int count = 0;
	char slect = 'Y';
	employee *tail, *q;
	head = (employee *)malloc(sizeof(employee));
	head->next = NULL;
	q = head;
	while (slect=='Y'||slect=='y')
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
void Search(employee *head)      //查询
{  
	int n;
	int flag = 1, ID;
	char  name[10];
	if (head == NULL) {
		printf("目前没有任何职工信息,请先输入职工信息或载入职工信息\n");
		system("pause");
		return;
	}
	Searchmenu();
	scanf("%d", &n);
	switch (n) {
	case 1:
		break;
	case 2:
		break;
	case 3:return;
		break;
	default:printf("输入有误，请重新选择\n"); system("pause"); Search(head);
		break;
	}
	if (n == 1) {	
		char slect = 'Y';
		flag = 1;
		while (slect == 'Y' || slect == 'y') {
			flag = 1;
			employee *p = head;
			system("cls");
			printf("请输入要查询职工的ID号: ");
			scanf("%d", &ID);
			while (p) {
				if (p->ID == ID) {
					if (flag == 1) {
						printf("ID        姓名      基本工资  职务工资  津贴  医疗保险  公积金  总工资\n");
					}
					flag++;
					printf("%04d      %s        %.2f      %.2f      %.2f  %.2f      %.2f    %.2f\n", p->ID, p->name, p->base, p->salary, p->allowance, p->insurance, p->fund, p->total);
				}
				p = p->next;
			}
			if (flag==1) {
				printf("查无此ID号为 %04d 的职工\n", ID);
			}
			printf("是否继续查询Y/N：");
			scanf(" %c", &slect);
			slect = Judge(slect);
		}
	}
	if (n == 2) {
		char slect = 'Y';
		flag = 1;
		while (slect == 'Y' || slect == 'y') {
			flag = 1;
			employee *p = head;
			system("cls");
			printf("请输入要查询职工的姓名: ");
			scanf("%s", &name);
			while (p) {
				if (strcmp(name, p->name) == 0) {
					if (flag == 1) {
						printf("ID        姓名      基本工资  职务工资  津贴  医疗保险  公积金  总工资\n");
					}
					flag++;
					printf("%04d      %s        %.2f      %.2f      %.2f  %.2f      %.2f    %.2f\n", p->ID, p->name, p->base, p->salary, p->allowance, p->insurance, p->fund, p->total);
				}
				p = p->next;
			}
			if (flag == 1) {
				printf("查无姓名为 %s 的职工\n", name);
			}
			printf("是否继续查询Y/N: ");
			scanf(" %c", &slect);
			slect = Judge(slect);
		}
	}
}
struct employee *Change(employee *head) {           //修改
	int n;
	int flag = 1, ID;
	char name[10], slect;
	if (head == NULL) {
		printf("目前没有任何职工信息,请先输入职工信息或载入职工信息\n");
		system("pause");
		return head;
	}
	Changemenu();
	scanf("%d", &n);
	switch (n) {
	case 1:
		break;
	case 2:
		break;
	case 3:return head;
		break;
	default:printf("输入有误，请重新选择\n"); system("pause"); Change(head);
		break;
	}
	if (n == 1) {
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
					printf("ID        姓名      基本工资  职务工资  津贴  医疗保险  公积金  总工资\n");
					printf("%04d      %s        %.2f      %.2f      %.2f  %.2f      %.2f    %.2f\n", temp.ID, temp.name, temp.base, temp.salary, temp.allowance, temp.insurance, temp.fund, temp.total);
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
						printf("ID        姓名      基本工资  职务工资  津贴  医疗保险  公积金  总工资\n");
						printf("%04d      %s        %.2f      %.2f      %.2f  %.2f      %.2f    %.2f\n", p->ID, p->name, p->base, p->salary, p->allowance, p->insurance, p->fund, p->total);
						break;
					}
				}
				p = p->next;
			}
			if (flag==1) {
				printf("查无此ID号为 %04d 的职工\n", ID);
			}
			printf("是否继续修改Y/N: ");
			getchar();
			scanf(" %c", &slect);
			slect = Judge(slect);
		}	
	}
	if (n == 2) {
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
					printf("ID        姓名      基本工资  职务工资  津贴  医疗保险  公积金  总工资\n");
					printf("%04d      %s        %.2f      %.2f      %.2f  %.2f      %.2f    %.2f\n", temp.ID, temp.name, temp.base, temp.salary, temp.allowance, temp.insurance, temp.fund, temp.total);
					printf("是否进行修改Y/N: ");
					scanf(" %c", &confirm);
					confirm = Judge(confirm);
					while(confirm=='Y'||confirm=='y'){
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
						printf("ID        姓名      基本工资  职务工资  津贴  医疗保险  公积金  总工资\n");
						printf("%04d      %s        %.2f      %.2f      %.2f  %.2f      %.2f    %.2f\n", p->ID, p->name, p->base, p->salary, p->allowance, p->insurance, p->fund, p->total);
						break;
					}				
				}
				p = p->next;
			}
			if (flag==1) {
				printf("查无姓名为 %s 的职工\n", name);
			}
			printf("是否继续修改Y/N: ");
			scanf(" %c", &slect);
			slect = Judge(slect);
		}
	}
	return head;
}

struct employee *Del(employee *head)                    //删除
{
	int n;
	int flag = 1;
	if (head == NULL) {
		printf("目前没有任何职工信息,请先输入职工信息或载入职工信息\n");
		system("pause");
		return head;
	}
	Delmenu();
	scanf("%d", &n);
	switch (n) {
	case 1:
		break;
	case 2:
		break;
	case 3:return head;
		break;
	default:printf("输入有误，请重新选择\n"); system("pause"); system("cls"); Del(head);
		break;
	}
	if (n == 1) {
		int ID;
		char slect = 'Y', confirm;
		while (slect == 'Y' || slect == 'y') {
			employee *p = head, *q;
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
					printf("ID        姓名      基本工资  职务工资  津贴  医疗保险  公积金  总工资\n");
				}
				flag++;
				printf("%04d      %s        %.2f      %.2f      %.2f  %.2f      %.2f    %.2f\n", p->ID, p->name, p->base, p->salary, p->allowance, p->insurance, p->fund, p->total);
				printf("请确认删除Y/N: ");
				scanf(" %c", &confirm);
				confirm = Judge(confirm);
				if (confirm == 'Y' || confirm == 'y') {
					q->next = p->next;
					printf("ID号为 %04d 的职工信息成功删除\n", ID);
				}
			}
		if (flag == 1) {
			printf("查无此ID号为 %04d 的职工\n", ID);
		}
		printf("是否继续删除Y/N: ");
		scanf(" %c", &slect);
		}
	}
	if (n == 2) {
		char slect = 'Y', name[10], confirm;
		while (slect == 'Y' || slect == 'y') {
			employee *p = head, *q;
			system("cls");
			flag = 1;
			printf("输入要删除的职工姓名: ");
			scanf("%s", &name);
			while (p->next&&strcmp(name, p->name))
			{
				q = p;
				p = p->next;
			}
			if (strcmp(name, p->name)==0) {
				printf("找到姓名为 %s 的职工信息如下: \n", name);
				if (flag == 1) {
					printf("ID        姓名      基本工资  职务工资  津贴  医疗保险  公积金  总工资\n");
				}
				flag++;
				printf("%04d      %s        %.2f      %.2f      %.2f  %.2f      %.2f    %.2f\n", p->ID, p->name, p->base, p->salary, p->allowance, p->insurance, p->fund, p->total);
				printf("请确认删除Y/N: ");
				scanf(" %c", &confirm);
				confirm = Judge(confirm);
				if (confirm == 'Y' || confirm == 'y') {
					q->next = p->next;
					printf("姓名为 %s 的职工信息成功删除\n", name);
				}
			}
			if (flag == 1) {
				printf("查无此姓名为 %s 的职工\n", name);
			}
			printf("是否继续删除Y/N: ");
			scanf(" %c", &slect);
			slect = Judge(slect);
		}
	}
	return head;
}
struct employee *Add(employee *head)                         //追加
{
	if (head == NULL) {
		printf("目前没有任何职工信息,请先输入职工信息或载入职工信息\n");
		system("pause");
		return;
	}
	int n, ID;
	char slect = 'Y', confirm;
	Addmenu();
	scanf("%d", &n);
	switch(n) {
	case 1:
		break;
	case 2:return;
		break;
	default:printf("输入有误，请重新选择\n"); system("pause"); system("cls"); Add(head);
		break;
	}
	employee *p, *q = head, *t;
	while (slect == 'Y' || slect == 'y') {
		p = (employee*)malloc(sizeof(employee));
		p->next = NULL;
		q = head;
		system("cls");
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
				printf("已经有ID为 %04d 的职工信息如下\n");
				printf("ID        姓名      基本工资  职务工资  津贴  医疗保险  公积金  总工资\n");
				printf("%04d      %s        %.2f      %.2f      %.2f  %.2f      %.2f    %.2f\n", q->ID, q->name, q->base, q->salary, q->allowance, q->insurance, q->fund, q->total);
				printf("是否覆盖原有职工信息Y/N: ");
				scanf(" %c", &confirm);
				confirm = Judge(confirm);
				if (confirm != 'Y' || confirm != 'y') {
					break;
				}
				q->ID = p->ID;
				strcpy(q->name, p->name);
				q->base = p->base;
				q->salary = p->salary;
				q->allowance = p->allowance;
				q->insurance = p->insurance;
				q->fund = p->fund;
				q->total = p->total;
				printf("已覆盖ID为 %04d 的职工信息\n", q->ID);
				break;
			}
			t = q;
			q = q->next;
		}
		t->next = p;
		t = p;
		t->next = NULL;
		printf("已追加ID为 %04d 的职工信息\n", ID);
		printf("是否继续添加Y/N: ");
		scanf(" %c", &slect);
		slect = Judge(slect);
	}
	return head;
}
void Statistics(employee *head)                   //统计
{
	int n, i = 0, temp;
	int total = 0;
	if (head == NULL) {
		printf("目前没有任何职工信息,请先输入职工信息或载入职工信息\n");
		system("pause");
		return;
	}
	char slect = 'Y';
	double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, totalsum = 0;
	double count1 = 0, count2 = 0, count3 = 0, count4 = 0;
	employee *p = head->next;
	employeelist *list = (employeelist *)malloc(sizeof(employeelist));
	while (p) {
		list[i].ID = p->ID;
		strcpy(list[i].name, p->name);
		list[i].base = p->base;
		list[i].salary = p->salary;
		list[i].allowance = p->allowance;
		list[i].insurance = p->insurance;
		list[i].fund = p->fund;
		list[i].total = p->total;
		i++;
		total += 1;
		sum1 += p->base;
		sum2 += p->salary;
		sum3 += p->allowance;
		sum4 += p->insurance;
		sum5 += p->fund;
		totalsum += p->total;
		if (p->total > 3000) {
			count4 += 1;
		}
		else {
			if (p->total > 2000) {
				count3 += 1;
			}
			else {
				if (p->total > 1000) {
					count2 += 1;
				}
				else {
					count1 += 1;
				}
			}
		}
		p = p->next;
	}
	while (slect == 'Y' || slect == 'y') {
		employee *p = head->next;
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
		case 4:return;
			break;
		default:printf("输入有误，请重新选择\n"); system("pause"); system("cls"); Statistics(head);
			break;
		}
		if (n == 1) {
			printf("各项工资平均工资及总工资情况如下: \n");
			printf("平均基本工资  平均职务工资  平均津贴  平均医疗保险  平均公积金  平均总工资\n");
			printf("%.2f           %.2f          %.2f      %.2f          %.2f        %.2f\n", sum1/total, sum2/total, sum3/total, sum4/total, sum5/total, totalsum/total);
		}
		if (n == 2) {
			printf("总工资在各个区间人数及所占比例情况如下: \n");
			printf("1000以下   %.0f    %.2f%%  \n1000~2000  %.0f    %.2f%%  \n2000~3000  %.0f    %.2f%%  \n3000以上   %.0f    %.2f%%\n", count1, 100 * count1 / total, count2, 100 * count2 / total, count3, 100 * count3 / total, count4, 100 * count4 / total);
		}
		if (n == 3) {
			bubble(list, i);
			printf("全部职工工资信息表及平均工资如下: \n");
			printf("ID        姓名      基本工资  职务工资  津贴  医疗保险  公积金  总工资\n");
			p = head->next;
			temp = i;
			while (temp--) {
				printf("%04d      %s         %-.2f      %-.2f     %-.2f  %-.2f      %-.2f    %-.2f\n", list[temp].ID, list[temp].name, list[temp].base, list[temp].salary, list[temp].allowance, list[temp].insurance, list[temp].fund, list[temp].total);
			}
			printf("平均基本工资  平均职务工资  平均津贴  平均医疗保险  平均公积金  平均总工资  总职工人数\n");
			printf("%-6.2f        %.2f           %.2f     %.2f          %.2f         %.2f      %d\n", sum1 / total, sum2 / total, sum3 / total, sum4 / total, sum5 / total, totalsum / total, total);
		}
		printf("是否继续统计职工信息Y/N:");
		scanf(" %c", &slect);
		slect = Judge(slect);
	}
}
void Save(employee *head)                      //保存文件
{
	FILE *fp;
	employee *p = head->next;
	if (head == NULL) {
		printf("目前没有任何职工信息,请先输入职工信息或载入职工信息\n");
		system("pause");
		return head;
	}
	if ((fp = fopen("E:\\C++\\text\\employee.txt", "w")) == NULL)
	{
		printf("文件打开失败\n");
		system("pause");
		return head;
	}
	while (p)
	{
		fprintf(fp, "%04d %s %f %f %f %f %f %f\n", p->ID, p->name, p->base, p->salary, p->allowance, p->insurance, p->fund, p->total);
		p = p->next;
	}
	fclose(fp);
	printf("职工信息保存成功!\n");
	system("pause");
	return head;
}
struct employee *Load(employee *head)            //载入信息
{
	FILE *fp;
	if ((fp = fopen("E:\\C++\\text\\employee.txt", "r")) == NULL)
	{
		printf("文件打开失败\n");
		system("pause");
		return head;
	}
	char ch = '0';
	ch = fgetc(fp);
	if (ch == EOF) {
		printf("文件为空,请先输入职工信息\n");
		system("pause");
		return head;
	}
	head = (employee*)malloc(sizeof(employee));
	head->next = NULL;
	employee *q;
	employee *p;
	q = head;
	p = (employee*)malloc(sizeof(employee));
	while (fscanf(fp, "%d %s %f %f %f %f %f %f", &p->ID, p->name, &p->base, &p->salary, &p->allowance, &p->insurance, &p->fund, &p->total)!=EOF)
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
struct employee *Quit(employee *head)                                      //退出菜单
{
	quitmenu();
	int n;
	scanf("%d", &n);
	switch (n) {
	case 1:exit(0);
		break;
	case 2:return head;
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
void bubble(employeelist* list, int n) {
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
