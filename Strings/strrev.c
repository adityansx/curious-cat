#include "strrev.h"

main()
{
	int count = 0;
	char string[100]; char rev[100];
	gets(string);

	while(string[count] != '\0')
		count++;

	strrev(&string, count);
}
