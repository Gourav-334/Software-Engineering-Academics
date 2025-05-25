#include <stdio.h>
#include <stdlib.h>

typedef struct people {char name[30]; struct people*next;} ppl;

static int n; static int num = 0; static int NUMBER;
static ppl*m = NULL; static ppl*head = NULL; static ppl*temp = NULL;

void traverse(int N);

int main()
{
	printf("Number of people: "); scanf("%d", &n);
	m = (ppl*)malloc(sizeof(ppl)); head = m; temp = m;

	for (int i=1; i<=n; i++)
	{
		printf("Enter person's name: "); scanf("%s", temp -> name); num++;
		m = (ppl*)malloc(sizeof(ppl));
		if (i==n) {temp -> next = NULL;}
		else if (i!=n) {temp -> next = m; temp = temp -> next;}
	} printf("\n"); temp = head;
	
	printf("__________________________________________________________________\n");
	while (temp -> next != NULL)
	{
		printf("Person name: %s\nNext address: %d\n\n", temp -> name, temp -> next);
		temp = temp -> next;
	} printf("Person name: %s\nNext address: %d\n\n", temp -> name, temp -> next);
	printf("__________________________________________________________________\n");
	temp = head;

	printf("Which node from backward? "); scanf("%d", &NUMBER); traverse(NUMBER);

	return 0;
}

void traverse(int N)
{
	printf("\nOK!\n");
	int j = num - N;

	printf("__________________________________________________________________\n");
	for (int j2=1; j2<=j; j2++) {temp = temp -> next;}
	printf("Person name: %s\nNext address: %d\n\n", temp -> name, temp -> next);
	temp = head;
	printf("__________________________________________________________________\n");
}