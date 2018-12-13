#include<stdio.h>
int main(void)
{
	int n, i, a[10], temp, min, max, index;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	min = max = a[0];
	for (i = 0; i < n; i++)
	{
		if (a[i] <= min)
		{
			min = a[i];
			index = i;
		}
	}
	temp = a[0];
	a[0] = min;
	a[index] = temp;
	for (i = 0; i < n; i++)
	{
		if (a[i] >= max)
		{
			max = a[i];
			index = i;
		}
	}
	temp = max;
	a[index] = a[n - 1];
	a[n - 1] = temp;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}
