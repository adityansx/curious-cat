main()
{
	int input, i, j;

	printf("Enter the number of rows: ");
	scanf("%d", &input);
	
	for (i = 1; i <= input; i++)
	{
		for(j = 1; j <= i; j++)
		{
				printf("* ");
		}
		printf("\n");
	}
}
