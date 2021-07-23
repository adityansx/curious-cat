void print_even(int*, int);//to print even valued elements in the entered array
void print_odd(int*, int);//to print odd valued elements in the entered array
void average(int*, int);//to print sum and average of the elements in the entered array
void max_min(int*, int);//to print the largest and smallest element in the entered array
void duplicate(int*, int);//to remove duplicate elements in the entered array
void reverse(int*, int); // to print the array in reverse order

main()
{
	int n, choice, choice2;

	system("clear");
//	printf("\e[H\e[2J\e[3J");//clears the screen
//	printf("\e[1;1H"); moves the cursor without erasing anything

	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	int array[n];

	printf("\nNow enter the elements in the array:\n");

	for(int a = 0; a < n; a++)
		scanf("%d", &array[a]);

	do
	{
		printf("\nNow enter your choice. Press\n1   to print the even valued elements\n2   to print the odd valued elemenets\n3   print the sum and average of the elements\n    of the array\n4   print the maximum and minimum element\n    of the array\n5   to remove duplicate elements from the array\n6   to print the array in reverse order\n7   to re-enter the array\n0   to exit\n\n");
		scanf("%d", &choice);
		printf("\n");

		switch(choice)
		{
			case 0:
				exit(0);
				break;
			
			case 1:
				print_even(array, n);
				break;

			case 2:
				print_odd(array, n);
				break;

			case 3:
				average(array, n);
				break;

			case 4:
				max_min(array, n);
				break;

			case 5:
				duplicate(array, n);
				break;

			case 6:
				reverse(array, n);
				break;

			case 7:
				main();
				break;

			default:
				printf("Invalid Input!\n");
		}	
		printf("\nEnter 1   for more operations on the entered array\n      2   to re-enter array\n      0   to exit\n");
		scanf("%d", &choice2);

		if(choice2 == 2)
			main();
	}

	while(choice2 != 0);	
}
void print_even(int *array, int n)
{
        printf("The even elements present in the a\
rray are:\n");

        for(int i = 0; i < n; i++)
        {
                if(array[i] % 2 == 0)
                        printf("%d ", array[i]);
        }
        printf("\n");
}

void print_odd(int *array, int n)
{
	printf("The odd elements present in the array are:\n");

	for(int i = 0; i < n; i++)
	{
		if(array[i] % 2 > 0)
			printf("%d ", array[i]);
	}
	printf("\n");
}

void average(int *array, int n)
{
	int sum = 0;

	for(int i = 0; i < n; i++)
	{
		sum += array[i];
	}

	printf("Sum = %d\nAverage = %d\n", sum, sum / n);
}

void max_min(int *array, int n)
{
	int max = array[0];
	int min = array[0];

	for(int i = 0; i < n; i++)
	{
		if(max < array[i])
			max = array[i];

		if(min > array[i])
			min = array[i];
	}

	printf("Max = %d\nMin = %d\n", max, min);
}

void duplicate(int *array, int n)
{
	int new_array[n], count = 0;

	printf("Array entered:\n");
	for(int i = 0; i < n; i++)
		printf("%d ", *(array + i));
	printf("\n");

	for(int i = 0; i < n; i++)
	{
		int j;

		for(j = 0; j < count; j++)//j doesn't increase if a duplicate element is found
		{
			if(array[i] == new_array[j])
				break;
		}
		/*the loop runs, and if there is a unique element, j becomes equal to count
		If a duplicate element is found, the loop breaks and j remains smaller than count*/

		if(j == count)//a new element is added if j == count
		{
			new_array[count] = array[i];
			count++;//count increases to accomodate a new unique element
		}
	}

	printf("\nArray after removing duplicate elements:\n");
	for(int i = 0; i < count; i++)//count will be equal to number of elements in the new_array
		printf("%d ", *(new_array + i));//array name acts as a pointer to the first element of the array
	printf("\n\n");
}

void reverse(int *array, int n)
{
	int i = n - 1;
	printf("The array in reverse order is:\n");
	for(; i >= 0; i--)
	{
		printf("%d ", array[i]);
	}

	printf("\n");
}
