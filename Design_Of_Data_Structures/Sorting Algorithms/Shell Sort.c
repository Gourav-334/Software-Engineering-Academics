#include <stdio.h>

int main()
{
	int n,temp,jump; printf("Number of elements in arr: "); scanf("%d", &n); int arr[n];
	for (int i=0; i<n; i++) {printf("arr[%d]: ", i); scanf("%d", &arr[i]);}

	for (int i=0; i<n/2; i++)
	{	
		if (n%2==0)
		{
			if (i+(n/2)<n)
			{
				if (arr[i]>arr[i+(n/2)])
				{
					temp = arr[i]; arr[i] = arr[i+(n/2)]; arr[i+(n/2)] = temp;
				}
			}
		}

		if (n%2==1)
		{
			if (i+1+(n/2)<n)
			{
				if (arr[i]>arr[i+1+(n/2)])
				{
					temp = arr[i]; arr[i] = arr[i+1+(n/2)]; arr[i+1+(n/2)] = temp;
				}
			}
		}
	}

	for (int i=0; i<n-2; i++)
	{
		if (arr[i]<=arr[i+2]) {i++; continue;}

		if (arr[i]>arr[i+2])
		{
			temp = arr[i]; arr[i] = arr[i+2]; arr[i+2] = temp;
			i -= 3;
		}
	}

	for (int i=1; i<n-2; i++)
	{
		if (arr[i]<=arr[i+2]) {i++; continue;}

		if (arr[i]>arr[i+2])
		{
			temp = arr[i]; arr[i] = arr[i+2]; arr[i+2] = temp;
			i -= 3;
		}
	}

	for (int i=0; i<n-1; i++)
	{
		if (arr[i]<=arr[i+1]) {continue;}

		if (arr[i]>arr[i+1])
		{
			temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp;
			i -= 2;
		}
	}

	for (int i=0; i<n; i++) {printf("%d  ", arr[i]);}

	return 0;
}