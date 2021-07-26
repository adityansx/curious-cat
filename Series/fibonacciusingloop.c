//Program to find fibonacci series using loop
main()
{
	int n1 = 0, n2 = 1, num, n3, i = 2;

	printf("Enter the number of terms: ");
	scanf("%d", &num);

	if(num == 1)
		printf("%d\n", n1);
	if(num == 2)
		printf("%d %d\n", n1, n2);
	if(num > 2)
	{
		while(i < num)
		{
			n3 = n2 + n1;
			printf("%d ", n3);

			n1 = n2;//n1 becomes the (n-2)th term
			n2 = n3;//n2 becomes the (n-1)th term
			i++;
		}
	}
	printf("\n");
}
