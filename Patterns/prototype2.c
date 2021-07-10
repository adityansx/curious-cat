main()
{
	int i, j, k = 0;
	char a[10] = {'a','b','c','d','e','f','g','h','i','j'};
	for (i=1; i<=4; i++)
	{
		for(j=4; j>=i; j--)
		{
				printf("%c ", a[k]);
				k++;
		}
		printf("\n");
	}
}
