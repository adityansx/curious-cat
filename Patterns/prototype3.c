main()
{
	int i, j;
	int a, b;
	char input;
	printf("\nEnter the alphabet you want to see in the last row:\n");
	scanf("%c", &input);
	if (input >= 65 || input <= 90)
	{
		char alphabet = 'A';
		for (i=1; i<= (input - 'A' + 1); i++)
		{
			for(j=1; j<=i; j++)
			{
					printf("%c ", alphabet);
			}
			++alphabet;
			printf("\n");
		}
	}
	else
	{
		char alphabet = 'a';
		
		for (a = 1; i <= (input - 'a' + 1); a++)
		{
			for (b = 1; b <= a; b++)
			{
				printf("%c ", alphabet);
			}
			++alphabet;
			printf("\n");
		}
	}
}
