main()
{
	int i, j, k = 0;
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	for (i=1; i<=5; i++)
	{
		for(j=1; j<i; j++)
		{
				printf("%d ", a[k]);
				k++;
		}
		printf("\n");
	}
}
