#include <stdio.h>
#include "plib.h"

int main()
{
	char string1[100], string2[100], *ch, dummy[1];
	int length1 = 0, length2 = 0, choice1, choice2, choice3 = 0, vowelcount = 0, compare;

	#ifdef CLRSCR
		while((getchar()) != '\n');
	#endif

	printf("Press enter to continue.\n");
	gets(dummy);
	
	printf("Enter the string:\n");
	gets(string1);

	printf("\nNow enter the second string (Press enter to skip):\n");
	gets(string2);
	
	while(string1[length1] != '\0')
		length1++;

	char stringrev[length1];

	do
	{
		printf("\nNow, enter your choice. Press\n");
		printf("1   to show address of characters in string\n");
		printf("2   to concatenate two strings\n");
		printf("3   to compare two strings\n");
		printf("4   to show the length of the string\n");
		printf("5   to convert all lowercase characters\n");
		printf("    to uppercase\n");
		printf("6   to convert all uppercase characters\n");
		printf("    to lowercase\n");
		printf("7   to show the number of vowels present\n");
		printf("    in the string\n");
		printf("8   to reverse the string\n\n");

		scanf("%d", &choice1);

		switch(choice1)
		{
			case 1:
				address(string1, length1);
				break;
			
			case 2:			
				printf("\nEnter 1   to concatenate using strcat function\n      2   to concatenate w/o using strcat function\n");
				scanf("%d", &choice2);

					switch(choice2)
					{
						case 1:
							#include <string.h>

							strcat(string1, string2);
							printf("\nThe new string is: %s\n\n", string1);
						
							break;
					
						case 2:
							while(string2[length2] != '\0')
							length2++;
							
							cat(string1, string2, length1, length2);

							break;
					

						default:
							printf("\nInvalid Input!\n\n");
					}
				break;

			case 3:
				#include <string.h>

				compare = strcmp(string1, string2);

				if(compare == 0)
					printf("\nThe first string and the second string are same.\n\n");

				else
					printf("\nThe first string and the second string are not the same.\n\n");
				
				break;

			case 4:
				ch = string1;
				int length = 0;

				while(*ch != '\0')
				{
					ch++;
					length++;
				}

				printf("\nLength of the entered string: %d\n\n", length);
				break;

			case 5:
				printf("\nEntered string: %s", string1);

				for(int i = 0; i < length1; i++)
				{
					if(string1[i] >= 97 && string1[i] <= 122)
						string1[i] = string1[i] - 32;
				}

				printf("\nConverted string: %s\n\n", string1);
				break;

			case 6:
				printf("\nEntered string: %s", string1);

				for(int i = 0; i < length1; i++)
				{
					if(string1[i] >= 65 && string1[i] <= 90)
						string1[i] = string1[i] + 32;
				}

				printf("\nConverted string: %s\n\n", string1);
				break;

			case 7:
				for(int i = 0; i < length1; i++)
				{
					if(string1[i] == 'a' || string1[i] == 'A' || string1[i] == 'e' || string1[i] == 'E' || string1[i] == 'i' || string1[i] == 'I' || string1[i] == 'o' || string1[i] == 'O' || string1[i] == 'u' || string1[i] == 'U')
						vowelcount++;
				}

				printf("\nNumber of vowels in the string: %d\n\n", vowelcount);
				break;

			case 8:
				for(int j = length1 - 1, i = 0; i < length1; i++, j--)
					stringrev[i] = string1[j];

				printf("\nEntered string: %s\n", string1);
				printf("Reversed string: %s\n\n", stringrev);

				break;

			case 0:
				exit(0);

			default:
				printf("Invalid Input!\n");
		}
		while((getchar()) != '\n');
		printf("Enter 1 for more operations on the same string\n      2 to enter a new string\n      0 to quit\n\n");
		scanf("%d", &choice3);

		switch(choice3)
		{
			case 0:
				exit(0);

			case 2:
				#define CLRSCR ;
				main();
		}
	}
	while(choice3 != 0);
}
