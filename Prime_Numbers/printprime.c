#include "prime.h"

void main()
{
	int starting, end;

	printf("Enter the beginning of the range: ");
	scanf("%d", &starting);

	printf("Enter the end of the range: ");
	scanf("%d", &end);

	printf("The prime numbers between %d and %d are: \n", starting, end);

	for(;starting <= end; starting++)
	{
		if(prime(starting, starting/2))
			printf("%d\t", starting);
	}
	printf("\n");
}
