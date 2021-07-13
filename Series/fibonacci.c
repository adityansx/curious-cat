/*Program to print the fibonaaci series by taking
the number of terms in the series as an input from
user.
*/
int fibonacci(int x)
{
	if (x == 0)
		return 0;
	if (x == 1)
		return 1;
	else
		return fibonacci(x - 1) + fibonacci(x - 2);
}

main()
{
	int a, n;

	printf("Enter the number of terms: ");
	scanf("%d", &n);

	for(a = 0; a < n; a++)
	{
		if (a == n - 1) //If it's the last term in the series, print the number and go to a new line.
			printf("%d\n", fibonacci(a));
		else
			printf("%d, ", fibonacci(a));
	}
}
