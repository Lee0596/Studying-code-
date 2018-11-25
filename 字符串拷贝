#include "stdio.h"
#define N 10
#define M 20

int my_strcpy_s(char str1[],int x,char str2[]);

void readline(char a[],int n)
{
  char ch;
  int i=0;
  while((ch=getchar())!='\n' && i<n-1)
   a[i++]=ch;
  a[i]='\0';
  return ;   
}

int main()
 {char a[N],b[M];
 readline(a,N);
 readline(b,M);
  if(!my_strcpy_s(a,N,b))
    puts("error!");
  puts(a);
  return 0;
 }

int my_strcpy_s(char str1[],int x,char str2[])
{
		int len, i;
	x -= 1;
	for (len = 0; str2[len] != '\0'; len++) {
	}
	for (i = 0; str2[i] != '\0'&&i < x; i++) {
		str1[i] = str2[i];
	}
	str1[i] = '\0';
	if (len > x) {
		return 0;
	}
	return 1;
}
