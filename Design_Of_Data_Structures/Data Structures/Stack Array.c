#include <stdio.h>

void display_array(int*ptr, int num);

void main()
{
	int n,m,brk; printf("Maximum elements in stack: "); scanf("%d", &n);
	int stack[n]; int choice, num = 0;
	
	printf("Static memory will occupy at max %d bytes.\n", n*sizeof(int));

	while (1)
	{
		printf("\n1: Push()\n2: Pop()\n3: Peek()\n4: Break\n\nChoice = "); scanf("%d", &choice);

		switch (choice) 
		{
			case 1:
				if (num<n) 
				{
					printf("Input element: "); scanf("%d", &stack[num]);
					num++; printf("\nPush completed!\n");
					if (m<num*sizeof(int)) {m += sizeof(int);}
					printf("Memory occupied statically = %d bytes\n\n", m);
				}

				else if (num==n) {printf("\nStack overflow!\n\n");}
				display_array(stack, num); break;

			case 2:
				if (num==0) {printf("\nStack underflow!\n\n");}
				else if (num>0) {num--; printf("Pop completed!\n");}
				printf("Memory occupied statically = %d bytes\n\n", m);
				display_array(stack, num); break;

			case 3: printf("\nPeek resultant: %d\n\n", stack[num-1]); break;

			case 4: brk = 1; break;
		}

		if (brk==1) {break;}
	}
}

void display_array(int*ptr, int num)
{
	printf("______________________________________________________________________\n");
	for (int i=0; i<num; i++)
	{
		if ((i==0)&&(num==i+1)) {printf("[%d]\n", *(ptr + i));}
		else if (i==0) {printf("[%d,", *(ptr + i));}
		else if (i==num-1) {printf("%d]\n", *(ptr + i));}
		else {printf("%d,", *(ptr + i));}
	}
	printf("______________________________________________________________________\n\n");
}