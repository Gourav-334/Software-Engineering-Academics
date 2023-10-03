#include <stdio.h>
#include <stdlib.h>

typedef struct people {char name[30]; struct people*prev; struct people*next;} ppl;

static int n, num = 0;
ppl*m = NULL; ppl*head = NULL; ppl*temp = NULL;

int main()
{
	printf("Number of people: "); scanf("%d", &n);
	m = (ppl*)malloc(sizeof(ppl)); head = m; temp = m;

	for (int i=1; i<=n; i++)
	{
		printf("Enter person's name: "); scanf("%s", temp -> name); num++;
		m = (ppl*)malloc(sizeof(ppl));
		if (i==1) {temp -> prev = NULL;}
		if (i==n) {temp -> next = NULL;}

		else if (i!=n) {m -> prev = temp; temp -> next = m; temp = temp -> next;}
	} printf("\n"); temp = head; free(m);
	
	printf("__________________________________________________________________\n");
	while (temp -> next != NULL)
	{
		printf("Person name: %s\nPrevious address: %d\nNext address: %d\n\n", 
			temp -> name, temp -> prev, temp -> next);

		temp = temp -> next;

	} printf("Person name: %s\nPrevious address: %d\nNext address: %d\n\n", 
		temp -> name, temp -> prev, temp -> next);
	printf("__________________________________________________________________\n");
	temp = head; 

	return 0;
}