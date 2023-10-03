#include <stdio.h>

int main()
{
	int sum=0,num=0,w=1,ch,n,temp;
	printf("Number of elements to be in array: "); scanf("%d", &n);
	printf("\n"); int hist[n];

	for (int i=0; i<n; i++) {printf("Array element %d: ", i+1); scanf("%d", &hist[i]);}
	for (int i=1; i<=n; i++) {sum += i;}

	int area[sum];

	for (int i=0; i<n; i++)
	{
		if (hist[i]==0) {continue;}
		w = 1; ch = hist[i];
		
		for (int j=i; j<n; j++)
		{
			if (hist[j]==0) {break;}
			if (hist[j]<ch) {ch = hist[j];}
			area[num] = w*ch;
			num++; w++;
		}
	}

	for (int i=0; i<sum*sum; i++)
	{
		for (int j=0; j<sum-1; j++)
		{
			if (area[j]>area[j+1]) {temp = area[j]; area[j] = area[j+1]; area[j+1] = temp;}
		}
	}

	printf("\n"); printf("Largest possible area is \"%d units\".\n", area[sum-1]);

	return 0;
}