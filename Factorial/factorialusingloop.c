//C Program to find factorial using loop
main()
{
	int a, b, fact = 1;

	printf("Enter the number: ");
	scanf("%d", &a);

	for(b = a; b >= 1; b--)
	{
		fact *= b;
	}

	printf("%d! is %d\n", a, fact);
}
