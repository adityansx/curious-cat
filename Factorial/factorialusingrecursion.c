//C program to find factorial of a number using recursion
int fact(int x)
{
	if(x == 0)
		return 1;
	else
		return x * fact(x -1);
}

main()
{
	int a;

	printf("Enter the number: ");
	scanf("%d", &a);

	printf("%d! is %d\n", a, fact(a));
}
