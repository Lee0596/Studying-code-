#include<stdio.h>
#include<math.h>
double f(double z, double x, double c, double v,double b);
int main() {
	double a, b, z, x, c, v;
	scanf("%lf %lf %lf %lf", &z, &x, &c, &v);
	scanf("%lf %lf", &a, &b);
	while ((b - a) >= 0.01) {
		if (f(z, x, c, v, a) == 0) {
			printf("%.2f", a);
			return 0;
		}
		if (f(z, x, c, v, b) == 0) {
			printf("%.2f", b);
			return 0;
		}
		if (f(z,x,c,v,(a + b) / 2) == 0) {
			printf("%.2f",(a+b)/2);
			return 0;
		}		
		if (f(z,x,c,v,(a + b) / 2)*f(z,x,c,v,a) >= 0) {
			a = (a + b) / 2;
		}
		else {
			b = (a + b) / 2;
		}
		if (b - a < 0.01) {
			printf("%.2f", (a + b) / 2);
			return 0;
		}
		
	}
	return 0;
}
double f(double z, double x, double c, double v, double b) {
	double f;
	f = z * pow(b, 3) + x * pow(b, 2) + c * b + v;
	return f;
}
