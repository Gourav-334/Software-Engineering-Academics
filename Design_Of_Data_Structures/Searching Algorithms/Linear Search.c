#include <stdio.h>

int main()
{
	int n,found=0,f; printf("Length of array: "); scanf("%d", &n); int arr[n];
	for (int i=0; i<n; i++) {printf("arr[%d]: ", i); scanf("%d", &arr[i]);}
	printf("Element to find: "); scanf("%d", &f);
	for (int i=0; i<n; i++) {if (arr[i]==f) {printf("%d found at index %d.", f,i); found = 1; break;}}
	if (found==0) {printf("%d not found in the array.", f);}

	return 0;
}