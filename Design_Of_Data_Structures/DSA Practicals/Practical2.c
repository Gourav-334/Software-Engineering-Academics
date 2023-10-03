#include <stdio.h>

void main()
{
	int n1,n2; int n3 = 0; int j = 0; int k = 0;

	printf("Number of elements in Set1: "); scanf("%d", &n1); int arr1[n1];
	for (int i=0; i<n1; i++)
	{
		printf("Set1, Element%d: ", i+1); scanf("%d", &arr1[i]);
	}

	printf("Number of elements in Set2: "); scanf("%d", &n2); int arr2[n2];
	for (int i2=0; i2<n2; i2++)
	{
		printf("Set2, Element%d: ", i2+1); scanf("%d", &arr2[i2]);
	}

	int arr3[n1+n2]; int array[n1+n2];

	for (int i3=0; i3<n1; i3++)
	{
		for (int i4=0; i4<n2; i4++)
		{
			if (arr1[i3]==arr2[i4])
			{
				array[j] = i3; j++;
			}
		}
	}

	for (int i6=0; i6<n1+n2; i6++)
	{
		if (i6==array[k])
		{
			k++; continue;
		}

		else {arr3[i6] = arr1[i6];}
	}

	for (int i7=0; i7<n2; i7++)
	{
		if (i7==array[k+n1])
		{
			k++; continue;
		}

		else {arr3[i7+n1] = arr2[i7];}
	}

	k = 0;

	printf("{");
	for (int i5=0; i5<n1+n2; i5++)
	{
		if (i5==array[k]) {k++; continue;}
		printf("%d,", arr3[i5]);
	} printf("}");
}