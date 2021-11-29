/*C Program to find binomial coefficient

Binomial Coefficient can be defined as the 
coefficient of x^r in the expansion of (1+x)^n.
*/
long int fact(long int a)
{
	if (a == 0)
		return 1;
	else
		return a * fact(a - 1);
}

main()
{
	int n, r;
	printf("Enter n: ");
	scanf("%d", &n);

	printf("Enter r: ");
	scanf("%d", &r);

	if (n >= r)
		printf("The value of C(%d, %d) is %ld\n", n, r, fact(n) / (fact(r) * fact(n - r)));

	else printf("The value of n must be greater than that of r.\
				\nExecute the program again and enter correct values.\n");
}
