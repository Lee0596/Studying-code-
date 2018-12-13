void reverse(int n) {
	printf("%d", n % 10);
	if (n / 10 != 0) reverse(n / 10);	
}
