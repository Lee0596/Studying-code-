#include <stdio.h>
struct data {       
	int molecule;
	int denominator;
};


int main(void)
{
	struct data s1, s2;
	double result1, result2;
	scanf("%d/%d %d/%d", &s1.molecule, &s1.denominator, &s2.molecule, &s2.denominator);
	result1 = ((double)s1.molecule / s1.denominator);
	result2 = ((double)s2.molecule / s2.denominator);
	if (result1 < result2) {
		printf("%d/%d < %d/%d", s1.molecule, s1.denominator, s2.molecule, s2.denominator);
	}
	else {
		if (result1 > result2) {
			printf("%d/%d > %d/%d", s1.molecule, s1.denominator, s2.molecule, s2.denominator);
		}
		else {
			printf("%d/%d = %d/%d", s1.molecule, s1.denominator, s2.molecule, s2.denominator);
		}
	}
	return 0;
}
