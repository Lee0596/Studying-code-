int getindex(char *s) {
	char*week[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
	int i;
	for (i = 0; i < 7; i++) {
		if (strcmp(*(week + i), s) == 0) {
			return i ;
		}
	}
	return -1;
}
