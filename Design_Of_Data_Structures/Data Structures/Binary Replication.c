#include <stdio.h>
#include <stdlib.h>

int offspring (int x);

typedef struct tree
{
	int value; int status;
	struct tree*parent;
	struct tree*child1; struct tree*child2;
}node;

void main()
{
	printf("stack_memory: OK!\nheap_memory: OK!\n\nProcess has started;\n\n");

	node*m; node*head; node*temp;
	float n = 0; float t = n;
	int gen,pop; int choice,gener,child; float children; int brk = 0;

	m = (node*)malloc(sizeof(node*));
	head = m; temp = m;
	temp -> parent = NULL;
	temp -> child1 = NULL; temp -> child2 = NULL;
	temp -> status = 0;

	printf("Enter value for 1st node: "); scanf("%d", &temp->value); printf("\n");
	n = 1.0; t = n; gen = 1; pop = 1;

	while (1)
	{
		temp = head;

		printf("1 = Replicate\n2 = Access\n3 = Kill branch\n");
		printf("4 = Exit process\n\nChoose operation on the binary tree: ");
		scanf("%d", &choice); printf("\n");
		
		switch (choice)
		{
			case 1:
				printf("Enter generation: "); scanf("%d", &gener);
				if (gener>gen) {printf("\nGeneration doesn't exist, try again.\n");break;}
				printf("Enter child number: "); scanf("%d", &child); children = (float) child;
				if (child>offspring(gen)) {printf("\nChild doesn't exist, try again.\n"); break;}
				children = (float) child;

				while (temp -> status != 0)
				{
					printf("\nCURRENT NODE VALUE: %d\n", temp -> value);///////////////////
					if (children/2.0<=1.0) {temp = temp -> child1; t /= 2.0;}
					else {temp = temp -> child2; t /= 2.0; children -= t;}
				} temp -> status = 1;

				printf("\nCURRENT NODE VALUE: %d\n", temp -> value);///////////////////////
				m = (node*)malloc(sizeof(node*));
				m -> parent = temp; temp -> child1 = m;
				printf("Enter 1st node value: "); scanf("%d", &m->value);
				m -> status = 0;

				m = (node*)malloc(sizeof(node*));
				m -> parent = temp; temp -> child2 = m;
				printf("Enter 2nd node value: "); scanf("%d", &m->value);
				m -> status = 0;

				if (gener==gen) {gen++; n *= 2.0;} t = n; pop += 2;
				printf("\nProcess completed!\n\n"); break;

			case 2:
				printf("Enter generation: "); scanf("%d", &gener);
				if (gener>gen) {printf("\nGeneration doesn't exist, try again.\n");break;}
				printf("Enter child number: "); scanf("%d", &child); children = (float) child;
				if (child>offspring(gen)) {printf("\nChild doesn't exist, try again.\n"); break;}
				children = (float) child;

				while (temp -> status != 0)
				{
					printf("\nCURRENT NODE VALUE: %d\n", temp -> value);///////////////////
					if (children/2.0<=1.0) {temp = temp -> child1; t /= 2.0;}
					else {temp = temp -> child2; t /= 2.0; children -= t;}
				}

				printf("\nCURRENT NODE VALUE: %d\n", temp -> value);///////////////////////
				printf("Value: %d\n", temp->value);
				printf("Status: %d\n", temp->status);
				printf("Parent address: %x\n", &temp->parent);
				printf("Child1 address: %x\n", &temp->child1);
				printf("Child2 address: %x\n", &temp->child2);

				printf("\nProcess completed!\n\n"); break;

			case 3:
				printf("Enter generation: "); scanf("%d", &gener);
				if (gener>gen) {printf("\nGeneration doesn't exist, try again.\n");break;}
				printf("Enter child number: "); scanf("%d", &child); children = (float) child;
				if (child>offspring(gen)) {printf("\nChild doesn't exist, try again.\n"); break;}
				children = (float) child; printf("\n");

				while (temp -> status != 0)
				{
					if (children/2.0<=1.0) {temp = temp -> child1; t /= 2.0;}
					else {temp = temp -> child2; t /= 2.0; children -= t;}
				}

				printf("temp = %d\n", temp);
				temp -> child1 = NULL; temp -> child2 = NULL;
				printf("%d bytes of memory freed!\n\n", sizeof(node*));
				break;

			case 4: brk = 1; break;
		}

		if (brk==1)
		{
			printf("Thanks a lot for taking part in testing!\n\n");
			printf("stack_memory: OFFLINE (unavailable)\n");
			printf("heap_memory: OFFLINE (unavailable)\n");
			break;
		}
	}
}

int offspring (int x)
{
	int y = 1;
	while (x!=1) {y *= 2; x--;}
	return y;
}