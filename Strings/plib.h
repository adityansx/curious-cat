void cat(char* string1, char* string2, int length1, int length2)
{	
	char string3[length1 + length2 + 1];
	int i;

	for(i = 0; i < length1; i++)
		string3[i] = string1[i];

	for(int j = 0; j < length2; j++, i++)
		string3[i] = string2[j];

	string3[i] = '\0';

	printf("\nThe string after concatenation: %s\n", string3);
}

void address(char* string, int length)
{
	int choice;

	printf("\nEnter 1 to show address of each element\n      2 to enter a character to show its address\n");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			for(int i = 0; i < length; i++)
			{
				printf("Address of %c = %x\n", string[i], &string[i]);
			}
			printf("\n");
			break;
			
		case 2:
			while((getchar()) != '\n');
			
			printf("Enter the character: ");
			char ch = getchar();

			for(int i = 0; i < length; i++)
			{
				if(ch == string[i] || (ch + 32) == string[i] || (ch - 32) == string[i])
				{
					printf("Address of %c = %x\n\n", string[i], &string[i]);
				}
			}
			break;
	}
}

