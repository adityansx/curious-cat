void strrev(char *string, int count)
{
	char rev[100];
	int begin, end = count - 1;

	for(begin = 0; begin < count; begin++)
	{
		rev[begin] = *(string + end);
		end--;
	}
	rev[begin] = '\0';

	puts(rev);

	int trig;
	printf("\nEnter 1 to check for palindrome ");
	scanf("%d", &trig);

	if(trig)
	{
		if(palindrome(string, &rev, count))
			printf("\nNot Palindrome\n");
		else
			printf("\nPalindrome\n");
	}
	else
		exit(0);
}

int palindrome(char *string, char *rev, int count)
{
	int begin, end = count - 1, mid = count / 2, flag = 0;

	for(begin = 0; begin < mid; begin++)
	{
		if(string[begin] != rev[end])
			flag = 1;
		end--;
	}
	return flag;
}
