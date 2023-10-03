#include <stdio.h>
#include <stdlib.h>

typedef struct Node {int value; struct Node*left; struct Node*right;} node;

node*m = NULL; node*temp = NULL; node*temp2 = NULL; node*head = NULL;
static int choice,input,comp,brk=0,height=0,num=0;

void insert(int n);

void main()
{
	while (1)
	{
		temp = head; temp2 = head; comp = 0; num = 0;
		printf("1: Insert\n2: Height\n3: Break\n\nChoice = "); scanf("%d", &choice);

		switch (choice)
		{
			case 1: printf("Give input value: "); scanf("%d", &input); insert(input); break;
			case 2: printf("Height = %d\n\n", height); break;
			case 3: brk = 1; break;
		}

		if (brk==1) {break;}
	}
}

void insert(int n)
{
	printf("\n");
	printf("__________________________________________________________________\n\n");

	if (temp==NULL)
	{
		m = (node*)malloc(sizeof(node)); head = m; temp = m;
		temp -> value = input; temp -> left = NULL; temp -> right = NULL;
		printf("PASSAGE NODE VALUE: %d\n", temp -> value); num++;
	}

	else if (temp!=NULL)
	{
		printf("PASSAGE NODE VALUE: %d\n", temp -> value); num++;

		while (comp==0)
		{
			if (input==temp->value)
			{
				if (temp->right==NULL)
				{
					m = (node*)malloc(sizeof(node)); temp -> right = m;
					m -> value = input; m -> left = NULL; m -> right = NULL;
				}

				else if ((temp->right!=NULL)&&(temp->right->value==input)) {temp = temp -> right;}

				else if ((temp->right!=NULL)&&(temp->right->value>input))
				{
					m = (node*)malloc(sizeof(node));
					m -> value = input; m -> left = NULL; m -> right = temp -> right;
					temp -> right = m;
				}

				comp = 1;
			}

			else if ((input<temp->value)&&(temp->left==NULL))
			{
				m = (node*)malloc(sizeof(node)); m -> value = input;
				temp -> left = m; temp -> left -> left = NULL; temp -> left -> right = NULL;
				temp = temp -> left; comp = 1;
			}

			else if ((input<temp->value)&&(temp->left!=NULL)) {temp = temp -> left;}

			else if ((input>temp->value)&&(temp->right==NULL))
			{
				m = (node*)malloc(sizeof(node)); m -> value = input;
				temp -> right = m; temp -> right -> left = NULL; temp -> right -> right = NULL;
				temp = temp -> right; comp = 1;
			}

			else if ((input>temp->value)&&(temp->right!=NULL)) {temp = temp -> right;}
			else {printf("\nFatal error code: 1\n\n"); comp = 1;}

			printf("PASSAGE NODE VALUE: %d\n", temp -> value); num++;
		}
	}

	if (num>height) {height = num;}

	printf("__________________________________________________________________\n\n");
}