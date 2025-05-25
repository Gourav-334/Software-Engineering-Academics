#include <stdio.h>

int main()
{
	int n; printf("Enter array size: "); scanf("%d", &n); int arr[n];
	for (int i=0; i<n; i++) {printf("arr[%d]: ", i); scanf("%d", &arr[i]);}
	int part = 2, low = 0, high = part-1, temp, flag = 0;

	while (flag != 1)
	{
		if (part > n)
		{
			part = n; low = 0; high = part-1;

			for (int i=low; i<high; i++)
			{
				if (arr[i]<=arr[i+1]) {continue;}

				if (arr[i]>arr[i+1])
				{
					temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp;
					if (i-1 >= low) {i -= 2;}
				}
			}

			flag = 1;
		}

		else if (n-1-high >= part)
		{
			for (int i=low; i<high; i++)
			{
				if (arr[i]<=arr[i+1]) {continue;}

				if (arr[i]>arr[i+1])
				{
					temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp;
					if (i-1 >= low) {i -= 2;}
				}
			}

			low += part; high += part;
		}

		else if (n-1-high < part)
		{
			for (int i=low; i<high; i++)
			{
				if (arr[i]<=arr[i+1]) {continue;}

				if (arr[i]>arr[i+1])
				{
					temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp;
					if (i-1 >= low) {i -= 2;}
				}
			}

			low += part; high = n-1;

			if (low < n)
			{
				for (int i=low; i<high; i++)
				{
					if (arr[i]<=arr[i+1]) {continue;}

					if (arr[i]>arr[i+1])
					{
						temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp;
						if (i-1 >= low) {i -= 2;}
					}
				}
			}

			part *= 2; low = 0; high = part-1;
		}
	}

	for (int i=0; i<n; i++) {printf("%d  ", arr[i]);}

	return 0;
}