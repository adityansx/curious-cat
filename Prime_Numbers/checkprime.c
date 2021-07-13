#include "prime.h"

void main()
{
	int a;

	printf("Enter the number: ");
	scanf("%d", &a);

	if(prime(a, a/2))
		printf("%d is a prime number.\n", a);
	else
		printf("%d is a composite number.\n", a);
}
