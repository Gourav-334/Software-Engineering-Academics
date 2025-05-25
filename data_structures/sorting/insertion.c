#include <stdio.h>

int main()
{
	int n,temp; printf("Number of elements in arr: "); scanf("%d", &n); int arr[n];
	for (int i=0; i<n; i++) {printf("arr[%d]: ", i); scanf("%d", &arr[i]);}

	for (int i=0; i<n-1; i++)
	{
		if (arr[i]<=arr[i+1]) {continue;}

		if (arr[i]>arr[i+1])
		{
			temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp;
			i -= 2;
		}
	}

	for (int i=0; i<n; i++) {printf("%d ", arr[i]);}

	return 0;
}