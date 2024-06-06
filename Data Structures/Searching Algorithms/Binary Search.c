#include <stdio.h>

int main()
{
	int n,found=0; printf("Enter size of array: "); scanf("%d", &n); int arr[n];

	for (int i=0; i<n; i++)
	{
		printf("arr[%d]: ", i); scanf("%d", &arr[i]);
		if ((i>0)&&(arr[i]<arr[i-1])) {i--; printf("The array must be sorted!\n"); continue;}
	}

	int start=0,end=n-1,f; printf("Element to find: "); scanf("%d", &f);

	for (int i=start; i<=end; i++)
	{
		n = (start + end)/2;

		if (arr[n]==f) {printf("\nSearch successful, %d found at index %d.\n", f,n); found = 1; break;}
		else if (f<arr[n]) {end = n - 1;} else if (f>arr[n]) {start = n + 1;}
		else {printf("Error code 1.");}
	}

	if (found==0) {printf("\nSearch unsuccessful.\n");}

	return 0;
}