int power(int x, int n)
{
	if (n == 0)
		return 1;
	else
		return x * power (x, n - 1);
}

main()
{
	int x, n;

	printf("Enter the number: ");
	scanf("%d", &x);
	printf("Enter its power: ");
	scanf("%d", &n);

	printf("%d ^ %d is %d\n", x, n, power(x, n));
}
