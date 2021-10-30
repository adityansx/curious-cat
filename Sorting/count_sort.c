int max(int arr[], int size)
{
	int m = arr[0];

	for(int i = 0; i < size; i++)
	{
		if(m < arr[i])
			m = arr[i];
	}
	
	return m;
}

#ifndef H

void countSort(int arr[], int size)
{
	int m = max(arr, size);
	int count[m + 1], result[size], a = 0;

	memset(count, 0, (m + 1) * sizeof(count[0]));

	for(int i = 0; i < size; i++)
		count[arr[i]]++;

	for(int i = 0; i <= m; i++)
	{
		while(count[i] != 0)
		{
			result[a] = i;
			--count[i]; ++a;
		}
	}

	for(int i = 0; i < size; i++)
		printf("%d ", result[i]);	
}

#endif

#ifdef H

void countSort(int* arr, int size, int exp)
{
	int count[10], output[size];
	memset(count, 0, 10 * sizeof(count[0]));

	for(int i = 0; i < size; i++)
		count[(arr[i] / exp) % 10]++;

	for(int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for(int i = size - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for(int i = 0; i < size; i++)
		arr[i] = output[i];
}

#endif

#ifndef H
	#define H
	
main()
{
	int arr[7] = {8, 6, 1, 6, 0, 9, 1};

	countSort(arr, (sizeof(arr) / sizeof(arr[0])));
}

#endif
