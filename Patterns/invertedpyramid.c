main()
{
	int i, j, spaces, rows;
	printf("\nEnter the number of rows: ");
	scanf("%d", &rows);
	for (i = rows; i >= 1; i--)
	{
		for (spaces = 0; spaces < rows - i; spaces++)
			{
				printf("  ");
			}
			for (j = 1; j<=i*2-1;j++)
			{
				printf("* ");
			}
			printf("\n");
	}
}
