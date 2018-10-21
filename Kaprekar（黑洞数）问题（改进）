
#include<stdio.h>

int main(){

	int i,max,min,num,f=0,a,b,c,t;

	scanf("%d",&num);

	while(num!=495||f==0){ 	
  
		a=num/100;b=num/10%10;c=num%10; 

		if(a<b) {t=a;a=b;b=t;} 	

		if(a<c) {t=a;a=c;c=t;}

		if(b<c) {t=b;b=c;c=t;}

		max=a*100+b*10+c; min=a+b*10+c*100;

		num=max-min;	f++;

		printf("%d: %d - %d = %d\n",f,max,min,num);

	}

	return 0;

} 
