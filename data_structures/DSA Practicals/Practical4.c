//Smallest, but same digits.
#include <stdio.h>
#include <string.h>

void main()
{
	int n,d,temp,z, max, min, max_i, min_i; static int arr[10];
	
	while (1)
	{
		z = 0; min = 10; max = -1;
		printf("Enter number: "); scanf("%d", &n);
		float y = (float) n; 

		while (y>=1)
		{
			y /= 10;
			arr[z] = n%10; n /= 10;
			z++;
		}

		d = z;

		for (int i=0; i<=d-1; i++)
		{
			if (i>(d/2)-1) {break;}

			temp = arr[i];
			arr[i] = arr[d-i-1];
			arr[d-i-1] = temp;
		}

		for (int l=d-1; l>0; l--)
		{
			if (arr[l]>max) {max = arr[l]; max_i = l; printf("max = %d\n", max);}
			if (arr[l]<min) {min = arr[l]; min_i = l; printf("min = %d\n", min);}
			
			if (arr[l]>arr[l-1])
			{
				arr[d-l-1] = min;
				arr[min_i] = arr[d-l-1];
				break;
			}
		}

		printf("Output: ");
		for (int k=0; k<d; k++)
		{
			printf("%d", arr[k]);
		} printf("\n\n");
	}
}