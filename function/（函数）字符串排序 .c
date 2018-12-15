void fsort(char *color[], int n) {
	int i, j;
	char*temp;
	for (i = 1; i < n; i++) {
		for (j = 0; j< n - 1; j++) {
			if (strcmp(*(color + i), *(color + j)) < 0) {
				temp = *(color + i);
				*(color + i) = *(color + j);
				*(color + j) = temp;
			}
		}
	}
}
