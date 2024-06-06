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
		printf("1: Push\n2: Pop\n3: Peek\n4: Break\n\nChoice: "); scanf("%d", &choice);

		switch (choice)
		{
			case 1: push(); break;
			case 2: pop(); break;
			case 3: peek(); break;
			case 4: brk = 1; break;
		}

		if (brk==1) {break;}
	}

	return 0;
}

void push()
{
	m = (ppl*)malloc(sizeof(ppl)); printf("Person's value: "); scanf("%s", &m -> name);

	for (int i=1; i<=num; i++)
	{
		if (i==num) {temp -> next = m; m -> next = NULL; num++; break;}
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

void pop()
{
	for (int i=1; i<=num; i++)
	{
		if (i==num-1) {m = temp -> next; temp -> next = NULL; free(m); num--; break;}
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

void peek()
{
	for (int i=1; i<=num; i++)
	{
		if (i==num)
		{
			printf("__________________________________________________________________\n\n");
			printf("Person name: %s\nNext address: %d\n\n", temp -> name, temp -> next);
			printf("__________________________________________________________________\n\n");
		}

		else {temp = temp -> next;}
	} temp = head;
}