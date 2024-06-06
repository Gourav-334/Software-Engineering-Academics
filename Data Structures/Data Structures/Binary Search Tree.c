#include <stdio.h>
#include <stdlib.h>

typedef struct Node {int value; struct Node*left; struct Node*right;} node;

node*m = NULL; node*temp = NULL; node*temp2 = NULL; node*head = NULL;
static int choice,input,comp,brk=0;

void insert(int n); void delete(int n); void search(int n);

void main()
{
	while (1)
	{
		temp = head; temp2 = head; comp = 0;
		printf("1: Insert\n2: Delete\n3: Search\n4: Break\n\nChoice = "); scanf("%d", &choice);

		switch (choice)
		{
			case 1: printf("Give input value: "); scanf("%d", &input); insert(input); break;
			case 2: printf("Give input value: "); scanf("%d", &input); delete(input); break;
			case 3: printf("Give input value: "); scanf("%d", &input); search(input); break;
			case 4: brk = 1; break;
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
		printf("PASSAGE NODE VALUE: %d\n", temp -> value);
	}

	else if (temp!=NULL)
	{
		printf("PASSAGE NODE VALUE: %d\n", temp -> value);

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

			printf("PASSAGE NODE VALUE: %d\n", temp -> value);
		}
	}

	printf("__________________________________________________________________\n\n");
}

void delete(int n)
{
	printf("\nNode removed successfully!\n\n");

	while (comp==0)
	{
	    printf("TRAVERSAL NODE VALUE: %d\n", temp -> value);
	    
		if (input==temp->value)
		{
			if ((temp->left==NULL)&&(temp->right==NULL)) 
				{free(temp); temp = NULL; head = NULL; comp = 1;}

			else if ((temp->left==NULL)&&(temp->right!=NULL))
				{head = head -> right; free(temp); comp = 1;}

			else if ((temp->left!=NULL)&&(temp->right==NULL))
				{head = head -> left; free(temp); comp = 1;}

			else if ((temp->left!=NULL)&&(temp->right!=NULL))
			{
				if (temp->right->left==NULL)
				{
					temp -> right -> left = head -> left;
					head = temp -> right; free(temp); comp = 1;
				}

				else if (temp->right->left!=NULL)
				{
					temp = temp -> right;
					while (temp->left!=NULL) {temp = temp -> left;}
					head -> value = temp -> value; free(temp); comp = 1;
				}

				else {printf("\nFatal error code: 2\n\n"); comp = 1;}
			}

			else {printf("\nFatal error code: 3\n\n"); comp = 1;}
		}

		else if ((input<temp->value)&&(input==temp->left->value))
		{
			if ((temp->left->left==NULL)&&(temp->left->right==NULL))
				{temp = temp -> left; free(temp); comp = 1;}

			else if (((temp->left->left==NULL)&&(temp->left->right!=NULL))||((temp->left->left!=NULL)&&(temp->left->right!=NULL)))
			{
				if (temp->left->right->left==NULL)
					{m = temp -> left; temp -> left = m -> right; free(m); comp = 1;}

				else if (temp->left->right->left!=NULL)
				{
					temp2 = temp -> left; temp = temp -> left -> right;
					
					while (temp->left!=NULL)
						{if (temp->left->left==NULL) {m = temp;} temp = temp ->left;}

					temp2 -> value = temp -> value; m -> left = NULL; free(temp); comp = 1;
				}

				else {printf("\nFatal error code: 4\n\n"); comp = 1;}
			}

			else if ((temp->left->left!=NULL)&&(temp->left->right==NULL))
			{
				if (temp->left->left->right==NULL)
					{m = temp -> left; temp -> left = m -> left; free(m); comp = 1;}

				else if (temp->left->left->right!=NULL)
				{
					temp2 = temp -> left; temp = temp -> left -> left;

					while (temp->right!=NULL)
						{if (temp->right->right==NULL) {m = temp;} temp = temp -> right;}

					temp2 -> value = temp -> value; m -> right = NULL; free(temp); comp = 1;
				}

				else {printf("\nFatal error code: 5\n\n"); comp = 1;}
			}
		}

		else if ((input<temp->value)&&(input!=temp->left->value)) {temp = temp -> left;}

		else if ((input>temp->value)&&(input==temp->right->value))
		{
			if ((temp->right->left==NULL)&&(temp->right->right==NULL))
				{m = temp -> right; temp -> right = NULL; free(m); comp = 1;}

			else if (((temp->right->left==NULL)&&(temp->right->right!=NULL))||((temp->right->left!=NULL)&&(temp->right->right!=NULL)))
			{
				if (temp->right->right->left==NULL)
					{m = temp -> right; temp -> right = m -> right; free(m); comp = 1;}

				else if (temp->right->right->left!=NULL)
				{
					temp2 = temp -> right; temp = temp -> right -> right;

					while (temp->left!=NULL)
						{if (temp->left->left==NULL) {m = temp;} temp = temp -> left;}
          
					temp2 -> value = temp -> value; m -> left = NULL; free(temp); comp = 1;
				}

				else {printf("\nFatal error code: 6\n\n"); comp = 1;}
			}

			else if ((temp->right->left!=NULL)&&(temp->right->right==NULL))
			{
				if (temp->right->left->right==NULL)
					{m = temp -> right; temp -> right = temp -> right -> left; free(m); comp = 1;}

				else if (temp->right->left->right!=NULL)
				{
					temp2 = temp -> right; temp = temp -> right -> left;

					while (temp->right!=NULL)
						{if (temp->right->right!=NULL) {m = temp;} temp = temp -> right;}

					temp2 -> value = temp -> value; m -> right = NULL; free(temp); comp = 1;
				}

				else {printf("\nFatal error code: 7\n\n"); comp = 1;}
			}

			else {printf("\nFatal error code: 8\n\n"); comp = 1;}
		}

		else if ((input>temp->value)&&(input!=temp->right->value)) {printf("WRONG: 1"); temp = temp -> right;}

		else {printf("\nFatal error code: 9\n\n"); comp = 1;}
		printf("TRAVERSAL NODE VALUE: %d\n", temp -> value);
	}
}

void search(int n)
{
	while (comp==0)
	{
		if (temp->value==input) {printf("\nElement found!\n"); comp = 1; break;}

		if ((temp->left==NULL)&&(temp->right==NULL))
			{printf("\nElement not found!\n"); comp = 1; break;}

		else if (input<temp->value) {temp = temp -> left;}
		else if (input>temp->value) {temp = temp -> right;}
	}
}