#include <stdio.h>

void display_array(int*ptr, int num);

void main()
{
	int n,m,brk; printf("Maximum elements in queue: "); scanf("%d", &n);
	int queue[n]; int choice, num = 0;
	
	printf("Static memory will occupy at max %d bytes.\n", n*sizeof(int));

	while (1)
	{
		printf("\n1: Enqueue()\n2: Dequeue()\n3: Inquire()\n4: Break\n\nChoice = ");
		scanf("%d", &choice);

		switch (choice) 
		{
			case 1:
				if (num<n) 
				{
					printf("Input element: "); scanf("%d", &queue[num]);
					num++; printf("\nEnqueue completed!\n");
					if (m<num*sizeof(int)) {m += sizeof(int);}
					printf("Memory occupied statically = %d bytes\n\n", m);
				}

				else if (num==n) {printf("\nQueue full!\n\n");}
				display_array(queue, num); break;

			case 2:
				for (int i=0; i<num-1; i++) {queue[i] = queue[i+1];}
				if (num==0) {printf("\nQueue empty!\n\n");}
				else if (num>0) {num--; printf("Dequeue completed!\n");}
				display_array(queue, num); break;

			case 3: printf("\nInquiry resultant: %d\n\n", queue[num-1]); break;

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