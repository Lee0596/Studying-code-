#include<stdio.h>
double max(int a);
double min(int a);

int main() {
	int a,i=1,b=0,c=0;
	scanf("%d",&a);
	if (a == 495) {
		b = max(a);
		c = min(a);
		a = max(a) - min(a);
		printf("%d: %d - %d = %d\n", i, b, c, a);
		return 0;
	}
	while (a != 495) {
		b = max(a);
		c = min(a);
		a = max(a) - min(a);
		printf("%d: %d - %d = %d\n", i, b, c, a);
		i++;
	}
	return 0;
}
double max(int a) {
	int b[3],i=0,t;
	for (i; i <= 2; i++) {
		b[i] = a % 10;
		a /= 10;
	}
	if (b[0] > b[1]) {
		t = b[0];
		b[0] = b[1];
		b[1] = t;	
	}
	if (b[0] > b[2]) {
		t = b[0];
		b[0] = b[2];
		b[2] = t;
	}
	if (b[1] > b[2]) {
		t = b[1];
		b[1] = b[2];
		b[2] = t;
	}
	t = b[2] * 100 + b[1] * 10 + b[0];
	return t;	
}
double min(int a) {
	int b[3], i = 0, t;
	for (i; i <= 2; i++) {
		b[i] = a % 10;
		a /= 10;
	}
	if (b[0] > b[1]) {
		t = b[0];
		b[0] = b[1];
		b[1] = t;
	}
	if (b[0] > b[2]) {
		t = b[0];
		b[0] = b[2];
		b[2] = t;
	}
	if (b[1] > b[2]) {
		t = b[1];
		b[1] = b[2];
		b[2] = t;
	}
	t = b[0] * 100 + b[1] * 10 + b[2];
	return t;
}
