#include <stdio.h>
#include <stdlib.h>

typedef struct bst {int value; struct bst*left; struct bst*right;} node;

static int choice,input,violation=0,brk=0;
static node*m = NULL; node*head = NULL; node*temp = NULL;

void main()
{
	m = (node*)malloc(sizeof(node));
	printf("Enter value for node: "); scanf("%d", &m->value);
	m -> left = NULL; m -> right = NULL; head = m; temp = m;
	printf("\n");

	while (1)
	{
		printf("1: Traverse left\n2: Traverse right\n3: Insert left\n4: Insert right\n");
		printf("5: Check BST or not\n6: Head reboot\n7: Break\n\nChoice? "); scanf("%d", &choice);
		printf("\n");

		switch (choice)
		{
			case 1:
				if (temp->left==NULL) {printf("Left pointer is NULL, try again.\n\n");}

				else if (temp->left!=NULL)
					{temp = temp -> left; printf("Moved to left by 1 unit.\n\n");}

				break;

			case 2:
				if (temp->right==NULL) {printf("Right pointer is NULL, try again.\n\n");}
				
				else if (temp->right!=NULL)
					{temp = temp -> right; printf("Moved to right by 1 unit.\n\n");}

				break;

			case 3:
				if (temp->left!=NULL) {printf("Left pointer is not NULL, try again.\n\n");}

				else if (temp->left==NULL)
				{
					m = (node*)malloc(sizeof(node)); temp -> left = m;
					printf("Enter value for node: "); scanf("%d", &m->value);
					m -> left = NULL; m -> right = NULL;

					if (m->value>=temp->value) {violation++;}
					temp = m; printf("Left insertion done successfully.\n\n");
				}

				break;

			case 4:
				if (temp->right!=NULL) {printf("Left pointer is not NULL, try again.\n\n");}

				else if (temp->right==NULL)
				{
					m = (node*)malloc(sizeof(node)); temp -> right = m;
					printf("Enter value for node: "); scanf("%d", &m->value);
					m -> left = NULL; m -> right = NULL;

					if (m->value<temp->value) {violation++;}
					temp = m; printf("Right insertion done successfully.\n\n");
				}

				break;

			case 5:
				if (violation>0)
					{printf("Not a BST, total %d violation(s).\n\n", violation);}

				else {printf("It is a BST.\n\n");}

				break;

			case 6: temp = head; printf("Rebooted to head node!\n\n"); break;
			case 7: brk = 1; break;
		}

		if (brk==1) {break;}
	}
}