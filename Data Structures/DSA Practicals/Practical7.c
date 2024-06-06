#include <stdio.h>
#include <stdlib.h>

typedef struct people {int value; struct people*next;} ppl;

static int n, num = 0, n2, num2 = 0, t, t2;
ppl*m = NULL; ppl*head = NULL; ppl*temp = NULL;
ppl*m2 = NULL; ppl*head2 = NULL; ppl*temp2 = NULL;

int main()
{
	printf("Number of people: "); scanf("%d", &n);
	m = (ppl*)malloc(sizeof(ppl)); head = m; temp = m;

	for (int i=1; i<=n; i++)
	{
		printf("Enter person's value: "); scanf("%d", &temp -> value); num++;
		m = (ppl*)malloc(sizeof(ppl));
		if (i==n) {temp -> next = NULL;}
		else if (i!=n) {temp -> next = m; temp = temp -> next;}
	} printf("\n"); temp = head; free(m);

	printf("\n__NEW___LINKED___LIST___STARTS__\n\n");

	printf("Number of people: "); scanf("%d", &n2);
	m2 = (ppl*)malloc(sizeof(ppl)); head2 = m2; temp2 = m2;

	for (int i=1; i<=n2; i++)
	{
		printf("Enter person's value: "); scanf("%d", &temp2 -> value); num2++;
		m2 = (ppl*)malloc(sizeof(ppl));
		if (i==n2) {temp2 -> next = NULL;}
		else if (i!=n2) {temp2 -> next = m2; temp2 = temp2 -> next;}
	} printf("\n"); temp2 = head2; free(m2);

	for (int i=0; i<=num*num; i++)
	{
		for (int j=1; j<=num-1; j++)
		{
			if (temp -> value > temp -> next -> value)
			{
				t = temp -> value;
				temp -> value = temp -> next -> value;
				temp -> next -> value = t;
			}
			temp = temp -> next;
		}
		if (i==num*num) {temp -> next = head2;} temp = head;
	}

	for (int i=0; i<=num2*num2; i++)
	{
		for (int j=1; j<=num2-1; j++)
		{
			if (temp2 -> value > temp2 -> next -> value)
			{
				t2 = temp2 -> value;
				temp2 -> value = temp2 -> next -> value;
				temp2 -> next -> value = t2;
			}
			temp2 = temp2 -> next;
		}
		temp2 = head2;
	}

	printf("__________________________________________________________________\n");
	while (temp -> next != NULL)
	{
		printf("Person value: %d\nNext address: %d\n\n", temp -> value, temp -> next);
		temp = temp -> next;
	} printf("Person value: %d\nNext address: %d\n\n", temp -> value, temp -> next);
	printf("__________________________________________________________________\n");
	temp = head;

	return 0;
}