int prime(int a, int b)
{
	if (b == 1)
		return 1;
	if (a % b == 0)
		return 0;
	return prime(a, b - 1);
}
