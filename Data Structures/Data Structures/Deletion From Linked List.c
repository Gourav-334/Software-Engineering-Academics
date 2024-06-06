#include <stdio.h>
#include <stdlib.h>

typedef struct people {char name[30]; struct people*next;} ppl;

static int n, del, choice, num = 0, brk = 0;
ppl*m = NULL; ppl*head = NULL; ppl*temp = NULL;

void deleteFirst(int del); void delete(int del);

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
	printf("__________________________________________________________________\n");
	temp = head; 

	while (1)
	{
		printf("1: Delete 1st node\n2: Delete\n3: Break\n\nChoice: "); scanf("%d", &choice);

		switch (choice)
		{
			case 1: del = 1; deleteFirst(del); break;
			case 2: printf("Which? "); scanf("%d", &del); delete(del); break;
			case 3: brk = 1; break;
		}

		if (brk==1) {break;}
	}

	return 0;
}

void deleteFirst(int del)
{
	head = head -> next; free(temp); num--; temp = head;

	printf("__________________________________________________________________\n");
	while (temp -> next != NULL)
	{
		printf("Person name: %s\nNext address: %d\n\n", temp -> name, temp -> next);
		temp = temp -> next;
	} printf("Person name: %s\nNext address: %d\n\n", temp -> name, temp -> next);
	printf("__________________________________________________________________\n\n");
	temp = head;
}

void delete(int del)
{
	for (int i=1; i<=num; i++)
	{
		if (i==del-1) {m = temp -> next; temp -> next = temp -> next -> next; break;}
		else {temp = temp -> next;}
	} free(m); num--; temp = head;

	printf("__________________________________________________________________\n");
	while (temp -> next != NULL)
	{
		printf("Person name: %s\nNext address: %d\n\n", temp -> name, temp -> next);
		temp = temp -> next;
	} printf("Person name: %s\nNext address: %d\n\n", temp -> name, temp -> next);
	printf("__________________________________________________________________\n\n");
	temp = head;
}