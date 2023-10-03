#include <stdio.h>

void insortBucket (int arr[], int arr2[], int arr3[], int n);

int main()
{
    int n; printf("Number of elements: "); scanf("%d", &n); int arr[n];
    for (int i=0; i<n; i++) {printf("arr[%d]: ", i); scanf("%d", &arr[i]);} printf("\n");

    int d = 1, arr2[n], arr3[n], flag = 0;

    for (int j=0; j<n; j++) {arr2[j] = arr[j];}
    for (int j=0; j<n; j++) {arr3[j] = arr[j];}

    for (int j=0; j<n; j++) {printf("%d ", arr[j]);} printf("\t(INITIAL)\n");

    while (flag == 0)
    {
    	for (int j=0; j<n; j++) {arr2[j] = arr3[j] % 10;}
    	insortBucket(arr,arr2,arr3,n);
    	for (int j=0; j<n; j++) {printf("%d ", arr[j]);} printf("\t(d = %d)\n", d);
    	for (int j=0; j<n; j++) {arr3[j] /= 10;}
    	for (int j=0; j<n; j++) {if (arr3[j] != 0) {break;} else if (j==n-1) {flag = 1;}}
    	d++;
    }

	return 0;
}

void insortBucket (int arr[], int arr2[], int arr3[], int n)
{
	int temp;

	for (int i=0; i<n-1; i++)
	{
		if (arr2[i]<=arr2[i+1]) {continue;}

		if (arr2[i]>arr2[i+1])
		{
			temp = arr2[i]; arr2[i] = arr2[i+1]; arr2[i+1] = temp;
			temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp;
			temp = arr3[i]; arr3[i] = arr3[i+1]; arr3[i+1] = temp;
			i -= 2;
		}
	}
}