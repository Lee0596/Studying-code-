#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include  <windows.h>
typedef struct employee
{
	int ID;
	char name[10];
	float base, salary, allowance, insurance, fund, total;
	struct employee *next;
}employee;
typedef struct employeelist
{
	int ID;
	char name[10];
	float base, salary, allowance, insurance, fund, total;
}employeelist;
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
		printf("*请请根据编号选择您要进行的操作:");
}
struct employee *Create(employee *head);       //建立
void Search(employee *head);                  //查找
void Searchmenu() {
	printf("******************** 查询职工信息 ********************\n");
	printf("*                    1-----按ID号查询                *\n");
	printf("*                    2-----按姓名查询                *\n");
	printf("*                    3-----返回                      *\n");
	printf("*请请根据编号选择您要进行的操作:");
}
struct employee *Change(employee *head);       //修改
void Changemenu() {
	printf("******************** 修改职工信息 ********************\n");
	printf("*                    1-----查询ID号修改              *\n");
	printf("*                    2-----查询姓名修改              *\n");
	printf("*                    3-----返回                      *\n");
	printf("*请请根据编号选择您要进行的操作:");
}
struct employee *Del(employee *head);          //删除
void Delmenu() {
	printf("******************** 删除职工信息 ********************\n");
	printf("*                    1-----查询ID号删除              *\n");
	printf("*                    2-----查询姓名删除              *\n");
	printf("*                    3-----返回                      *\n");
	printf("*请请根据编号选择您要进行的操作:");
}
struct employee *Add(employee *head);          //追加
void Addmenu() {
	printf("******************** 添加职工信息 ********************\n");
	printf("*                    1-----输入ID号追加              *\n");
	printf("*                    2-----返回                      *\n");
	printf("*请请根据编号选择您要进行的操作:");
}
void Statistics(employee *head);              //统计
void Statisticsmenu() {
	printf("**************************** 统计职工信息 ****************************\n");
	printf("*                    1-----统计各项工资平均工资及总工资              *\n");
	printf("*                    2-----统计总工资在各个区间人数及所占比例        *\n");
	printf("*                    3-----打印全部职工工资信息表及平均工资          *\n");
	printf("*                    4-----返回                                      *\n");
	printf("*请请根据编号选择您要进行的操作:");
}
void Save(employee *head);                       //保存信息
struct employee *Load(employee *head);            //载入信息
struct employee *Quit();                            //退出菜单
void quitmenu() {
	printf("****************************退出菜单 ****************************\n");
	printf("*                    1-----请确认您已保存职工信息               *\n");
	printf("*                    2-----返回                                 *\n");
	printf("*请请根据编号选择您要进行的操作:");
}
char Judge(char);     //输入错误
void bubble(employeelist* , int);         //排序
