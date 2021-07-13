main()
{
	int x, n, result = 1;

	printf("Enter the number: ");
	scanf("%d", &x);
	printf("Enter its power: ");
	scanf("%d", &n);

	printf("%d ^ %d is ", x, n);

	if (n == 0)
		printf("%d\n", result);
	else
		while (n != 0)
		{
			result *= x;
			--n;
		}
		printf("%d\n", result);
}
