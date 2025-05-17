#include <stdio.h>

int main()
{
	int n; printf("Number of elements to be in array: "); scanf("%d", &n);
	int arr[n]; int f,s,k,temp;

	for (int i=0; i<n; i++) {printf("arr[%d]: ", i); scanf("%d", &arr[i]);}
	
	for (int i=0; i<n; i++)
	{
		f = 0; s = arr[i];

		for (int j=i; j<n; j++)
		{
			if (arr[j]<s) {f = 1; s = arr[j]; k = j;}
		}

		if (f==1) {temp = arr[i]; arr[i] = arr[k]; arr[k] = temp;}
		for (int k=0; k<n; k++) {printf("%d, ", arr[k]);}
		printf("\n");
	}

	for (int i=0; i<n; i++) {printf("%d ", arr[i]);}

	return 0;
}