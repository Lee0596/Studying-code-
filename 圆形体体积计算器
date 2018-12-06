#include <stdio.h>
#include <string.h>
double pi = 3.1415926535;
void  VBall() {
	double r;
	double V;
	printf("Please enter the radius:\n");
	scanf("%lf", &r);
	V = 4.0 / 3 * pi*r*r*r;
	printf("%.2f\n", V);
}
void  VCylinder() {
	double r, h;
	double V;
	printf("Please enter the radius and the height:\n");
	scanf("%lf %lf", &r,&h);
	V = pi *r*r*h;
	printf("%.2f\n", V);
}
void  VCone() {
	double r, h;
	double V;
	printf("Please enter the radius and the height:\n");
	scanf("%lf %lf", &r, &h);
	V = pi *r*r*h/3;
	printf("%.2f\n", V);
}
int main()
{
	int slect;
	printf("1-Ball\n2 - Cylinder\n3 - Cone\nother - Exit\nPlease enter your command : \n");
	while (1) {
		scanf("%ld", &slect);
		switch (slect) {
		case 1: VBall(); break;
		case 2: VCylinder(); break;
		case 3: VCone(); break;
		default: return 0;
		}
		printf("1-Ball\n2 - Cylinder\n3 - Cone\nother - Exit\nPlease enter your command : \n");
	}
	return 0;
}
