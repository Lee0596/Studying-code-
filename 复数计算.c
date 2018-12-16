#include <stdio.h>
double result_real, result_imag;
void complex_prod(double x1, double y1, double x2, double y2);
void complex_add(double x1, double y1, double x2, double y2);
int main(void)
{
	double imag1, imag2, real1, real2;
	scanf("%lf %lf", &real1, &imag1);
	scanf("%lf %lf", &real2, &imag2);
	complex_add(real1, imag1, real2, imag2);
	if (result_imag < 0) {
		printf("addition of complex is %f%fi\n", result_real, result_imag);
	}
	else {
		printf("addition of complex is %f+%fi\n", result_real, result_imag);
	}
	complex_prod(real1, imag1, real2, imag2);
	if ((imag1 < 0 || imag2 < 0) || result_imag>=0) {
		printf("product of complex is %f+%fi\n", result_real, (unsigned)result_imag);
	}
	else {
		printf("product of complex is %f%fi\n", result_real, result_imag);
	}
	return 0;
}
void complex_prod(double x1, double y1, double x2, double y2) {
	result_real = (x1*x2 - y1 * y2);
	result_imag = (x1*y2 + x2 * y1);
}
void complex_add(double x1, double y1, double x2, double y2) {
	result_real = x1 + x2;
	result_imag = y1 + y2;
}
