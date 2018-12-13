
int reverse(int number) {
	int sum = 0, a = 0;
	if (number < 0) {
		number *= -1;
		a = 1;
	}
	if (number % 10 == 0) {
		number /= 10;
	}
	while (number != 0) {
		sum = sum * 10 + number % 10;
		number /= 10;
	}
	if (a) {
		return -1 * sum;
	}
	return sum;
}
