#include <stdio.h>
#include <string.h>

main()
{
	char s[100], s_new[100];
	int length;

	printf("Enter the string:\n");
	fgets(s, 100, stdin);

	length = strlen(s);

	for(int i = 0, a = length - 1; i < length; i++)
	{
		s_new[i] = s[a];
		a--;
	}

	printf("\nEntered string:\n%s", s);
	printf("\nReversed string:\n%s\n", s_new);
}
