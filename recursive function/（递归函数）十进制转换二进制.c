void dectobin(int n) {
	if (n == 0||n==1) {
		printf("%d",n);
	}else
	{
		dectobin(n / 2);
		printf("%d", n % 2);
	}
}
