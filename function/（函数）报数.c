void CountOff(int n, int m, int out[])
{
	int i;
	for ( i = 0; i < n; i++)
		out[i] = 0;
	int index, location;
	location = 0;
	for (i = 1; i <= n; i++)
	{
		index = 0;
		while (index < m)
		{
			if (out[location] == 0)
				index++;
			if (index == m)
				out[location] = i;
			location = (location + 1) % n;
		}
	}
}
