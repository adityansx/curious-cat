main()
{
	int i, j, spaces, rows;

	printf("Enter the number of rows: ");
	scanf("%d", &rows);

	for(i = 1; i <= rows; i++)
	{
		for(spaces = 1; spaces <= rows - i; spaces++)
		{
			printf("  ");
		}

		for(j = 1; j <= 2 * i - 1; j++)
		{
			printf("* ");
		}

		printf("\n");
	}
}
