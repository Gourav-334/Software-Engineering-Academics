#include <stdio.h>
#include <stdlib.h>

typedef struct numbers{ int value; struct numbers*next; }node;

void main()
{
	node*m; node*temp; node*head; node*tail;
	int n = 0; int brk = 0; int num,choice,q;

	printf("How many nodes you want? ");
	scanf("%d", &num);
	m = (node*)malloc(sizeof(node*));
	printf("\n");

	for (int i=1; i<=num; i++)
	{
		temp = m;
		m = (node*)malloc(sizeof(node*));
		printf("Kindly type value of node %d: ", n+1);
		scanf("%d", &temp -> value);
			
		if (n==num-1) { temp -> next = head; }
		else if (n>=0 && n<=num-2) { temp -> next = m; }
		else { printf("Invalid input...\n"); }
		n++;

		if (n==1) { head = temp; }
		if (n==num) { tail = temp; }
	}

	temp = head;

	printf("________________________________________________________________________\n\n");
	for (int i2=1; i2<=n; i2++)
	{
		printf("Node value: %d\nNext address: %d\n\n", temp -> value, temp -> next);
		if (i2!=n) { temp = temp -> next; }
	}
	printf("________________________________________________________________________\n\n");
}