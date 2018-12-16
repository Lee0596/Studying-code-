#include <stdio.h>
#include <math.h>
#include <string.h>
 struct math
{
	double real;
	double imag;
};
int main(int argc, char *argv[])
{
    struct math a[6];
	int i;
	scanf("%lf %lf %lf %lf", &a[0].real, &a[0].imag, &a[1].real, &a[1].imag);
	a[2].real = a[0].real + a[1].real;
	a[2].imag = a[0].imag + a[1].imag;
	a[3].real = a[0].real - a[1].real;
	a[3].imag = a[0].imag - a[1].imag;
	a[4].real = a[0].real*a[1].real - a[0].imag*a[1].imag;
	a[4].imag = a[0].real*a[1].imag + a[1].real*a[0].imag;
	a[5].real = (a[0].real*a[1].real + a[0].imag*a[1].imag) / (a[1].real*a[1].real + a[1].imag*a[1].imag);
	a[5].imag = (a[1].real*a[0].imag - a[0].real*a[1].imag) / (a[1].real*a[1].real + a[1].imag*a[1].imag);
	for (i = 2; i < 6; i++)
	{
		if (a[0].imag >= -0.05)
		{
			printf("(%.1f+%.1fi) ", a[0].real, a[0].imag);
		}
		else
		{
			printf("(%.1f%.1fi) ", a[0].real, a[0].imag);
		}
		if (i == 2)
		{
			printf("+ ");
		}
		else if (i == 3)
		{
			printf("- ");
		}
		else if (i == 4)
		{
			printf("* ");
		}
		else
		{
			printf("/ ");
		}
		if (a[1].imag >= -0.05)
		{
			printf("(%.1f+%.1fi) = ", a[1].real, a[1].imag);
		}
		else
		{
			printf("(%.1f%.1fi) = ", a[1].real, a[1].imag);
		}
		if (a[i].real > 0.05 || a[i].real < -0.05)
		{
			printf("%.1f", a[i].real);
		}

		if (a[i].imag > 0.05 || a[i].imag < -0.05)
		{
			if ((a[i].real > 0.05 || a[i].real < -0.05) && a[i].imag > 0)
			{
				printf("+");
			}
			printf("%.1fi", a[i].imag);
		}
		if (a[i].real > -0.05&&a[i].real<0.05&&a[i].imag>-0.05&&a[i].imag < 0.05)
		{
			printf("0.0");
		}
		printf("\n");
	}
	return 0;
}
