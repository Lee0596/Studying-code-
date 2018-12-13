void bubble(int a[], int n) {
	int i, j, t;
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) {
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}
