void strmcpy(char *t, int m, char *s) {
	int i;
	for (i = 0; t[i] != '\0'; i++) {};
	if (m > i)
		*s = NULL;
	else
	{
		m -= 1;
		for (i=0; t[m]!='\0'; m++,i++)
			s[i] = t[m];
	}
}
