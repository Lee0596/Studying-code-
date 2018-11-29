void month_day(int year, int yearday, int * pmonth, int * pday) {
	int a[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }, i, sum = 0;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		sum += 1;
	}
	for (i = 0; (yearday - sum) > a[i]; i++) {
		sum += a[i];
	}
	*pmonth = i;
	*pday = yearday - sum;
}

