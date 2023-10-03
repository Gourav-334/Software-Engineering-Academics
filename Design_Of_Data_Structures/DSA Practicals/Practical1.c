//Next greatest integer in series.
#include <stdio.h>

void main()
{
	int arr[8] = {7,9,1,8,2,0,5,4};
	int arr0[8];
	int index; int temp = 100; int found = 0;

	while (1)
	{
		printf("\n\nGreatest to which element? ");
		scanf("%d", &index); temp = 100;

		for (int i=0; i<8; i++)
		{
			arr0[i] = arr[i] - arr[index];
		}

		for (int i2=index; i2<8; i2++)
		{
			if ((arr0[i2]<temp)&&(arr0[i2]>0))
			{
				temp = arr[i2];
			}
		}

		if (temp==100) {printf("\nNone!\n\n");}
		else {printf("\n%d\n\n", temp);}
	}
}