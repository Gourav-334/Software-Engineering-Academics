#include <stdio.h>
#include <stdlib.h>

typedef struct people {char name[30]; struct people*next;} ppl;

static int n, ins, choice, num = 0, brk = 0;
ppl*m = NULL; ppl*head = NULL; ppl*temp = NULL;

void insert(int ins); void insertLast(int ins);

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
	} printf("\n"); temp = head; free(m);
	
	printf("__________________________________________________________________\n");
	while (temp -> next != NULL)
	{
		printf("Person name: %s\nNext address: %d\n\n", temp -> name, temp -> next);
		temp = temp -> next;
	} printf("Person name: %s\nNext address: %d\n\n", temp -> name, temp -> next);
	printf("__________________________________________________________________\n\n");
	temp = head; 

	while (1)
	{
		printf("1: Insert\n2: Last node insert\n3: Break\n\nChoice: "); scanf("%d", &choice);

		switch (choice)
		{
			case 1: printf("Where? "); scanf("%d", &ins); insert(ins); break;
			case 2: printf("Where? "); scanf("%d", &ins); insertLast(ins); break;
			case 3: brk = 1; break;
		}

		if (brk==1) {break;}
	}

	return 0;
}

void insert(int ins)
{
	m = (ppl*)malloc(sizeof(ppl)); printf("Person's name: "); scanf("%s", &m -> name);

	for (int i=1; i<=num; i++)
	{
		if (i==ins-1) {m -> next = temp -> next; temp -> next = m; num++; break;}
		else {temp = temp -> next;}
	} temp = head;

	printf("__________________________________________________________________\n");
	while (temp -> next != NULL)
	{
		printf("Person name: %s\nNext address: %d\n\n", temp -> name, temp -> next);
		temp = temp -> next;
	} printf("Person name: %s\nNext address: %d\n\n", temp -> name, temp -> next);
	printf("__________________________________________________________________\n\n");
	temp = head;
}

void insertLast(int ins)
{
	m = (ppl*)malloc(sizeof(ppl)); scanf("%s", &m -> name);

	for (int i=1; i<=num; i++)
	{
		if (i==ins) {temp -> next = m; m -> next = NULL; num++;}
		else {temp = temp -> next;}
	} temp = head;

	printf("__________________________________________________________________\n");
	while (temp -> next != NULL)
	{
		printf("Person name: %s\nNext address: %d\n\n", temp -> name, temp -> next);
		temp = temp -> next;
	} printf("Person name: %s\nNext address: %d\n\n", temp -> name, temp -> next);
	printf("__________________________________________________________________\n\n");
	temp = head;
}