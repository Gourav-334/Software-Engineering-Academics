#include <stdio.h>

void qsort (int arr[], int low, int high, int n);

int main()
{
    int n; printf("Number of elements to be in array: "); scanf("%d", &n);
    int arr[n]; for (int i=0; i<n; i++) {printf("arr[%d]: ", i); scanf("%d", &arr[i]);}
    
    qsort(arr,0,n-1,n);

    for (int i=0; i<n; i++) {printf("%d  ", arr[i]);} printf("\n");
    
    return 0;
}

void qsort (int arr[], int low, int high, int n)
{
    int pivot = arr[high], left = low, right = high, l = 0, r = 0, exact;
    int arr2[n]; for (int i=0; i<n; i++) {arr2[i] = arr[i];}

    for (int i=low; i<=high-1; i++)
    {
        if (arr2[i] <= pivot) {arr[left] = arr2[i]; left++; l++;}
        else if (arr2[i] > pivot) {arr[right] = arr2[i]; right--; r++;}
    }

    arr[left] = pivot; exact = left;
    
    if (l > 1) {qsort(arr,low,exact-1,n);}
    if (r > 1) {qsort(arr,exact+1,high,n);}
    else {return;}
}