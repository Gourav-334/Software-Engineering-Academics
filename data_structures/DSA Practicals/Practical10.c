#include <stdio.h>
#include <stdlib.h>

typedef struct Node {int value; struct Node*left; struct Node*right;} node;
typedef struct people {int par; int value; int gen; struct people*next;} ppl;

node*m = NULL; node*temp = NULL; node*head = NULL; static int num = 0, height;
node*m2 = NULL; node*temp2 = NULL; node*head2 = NULL; static int num2 = 0, height2;

ppl*m3 = NULL; ppl*head3 = NULL; ppl*temp3 = NULL; static int num3 = 0;
ppl*m4 = NULL; ppl*head4 = NULL; ppl*temp4 = NULL; static int num4 = 0;

static int choice,input,comp,brk=0,t,t2;

void insert1(int n); void insert2(int n); void mirror();

void main()
{
	while (1)
	{
		temp = head; temp2 = head2; temp3 = head3; temp4 = head4; comp = 0; num = 0; num2 = 0;
		printf("1: Insert in tree1\n2: Insert in tree2\n3: Check mirroring\n4: Break\n\nChoice = "); 
		scanf("%d", &choice);

		switch (choice)
		{
			case 1: printf("Give input value: "); scanf("%d", &input); insert1(input); break;
			case 2: printf("Give input value: "); scanf("%d", &input); insert2(input); break;
			case 3: mirror(); break;
			case 4: brk = 1; break;
		}

		if (brk==1) {break;}
	}
}

void insert1(int n)
{
	printf("\n");
	printf("__________________________________________________________________\n\n");

	if (temp==NULL)
	{
		m = (node*)malloc(sizeof(node)); head = m; temp = m;
		temp -> value = input; temp -> left = NULL; temp -> right = NULL;

		printf("1st PASSAGE NODE VALUE: %d\n", temp -> value); num++;

		m3 = (ppl*)malloc(sizeof(ppl)); head3 = m3; temp3 = m3;
		m3 -> par = NULL; m3 -> value = temp -> value; m3 -> next = NULL;
	}

	else if (temp!=NULL)
	{
		printf("1st PASSAGE NODE VALUE: %d\n", temp -> value); num++;

		while (temp3->next!=NULL) {temp3 = temp3 -> next;}
		m3 = (ppl*)malloc(sizeof(ppl));
		temp3 -> next = m3;

		while (comp==0)
		{
			if (input==temp->value)
			{
				if (temp->right==NULL)
				{
					m3 -> par = temp -> value;
					m = (node*)malloc(sizeof(node)); temp -> right = m;
					m -> value = input; m -> left = NULL; m -> right = NULL;
					m3 -> value = temp -> value; m3 -> next = NULL;
				}

				else if ((temp->right!=NULL)&&(temp->right->value==input)) {temp = temp -> right;}

				else if ((temp->right!=NULL)&&(temp->right->value>input))
				{
					m3 -> par = temp -> value;
					m = (node*)malloc(sizeof(node));
					m -> value = input; m -> left = NULL; m -> right = temp -> right;
					temp -> right = m;
					m3 -> value = temp -> value; m3 -> next = NULL;
				}

				comp = 1;
			}

			else if ((input<temp->value)&&(temp->left==NULL))
			{
				m3 -> par = temp -> value;
				m = (node*)malloc(sizeof(node)); m -> value = input;
				temp -> left = m; temp -> left -> left = NULL; temp -> left -> right = NULL;
				temp = temp -> left; comp = 1;
				m3 -> value = temp -> value; m3 -> next = NULL;
			}

			else if ((input<temp->value)&&(temp->left!=NULL)) {temp = temp -> left;}

			else if ((input>temp->value)&&(temp->right==NULL))
			{
				m3 -> par = temp -> value;
				m = (node*)malloc(sizeof(node)); m -> value = input;
				temp -> right = m; temp -> right -> left = NULL; temp -> right -> right = NULL;
				temp = temp -> right; comp = 1;
				m3 -> value = temp -> value; m3 -> next = NULL;
			}

			else if ((input>temp->value)&&(temp->right!=NULL)) {temp = temp -> right;}
			else {printf("\nFatal error code: 1\n\n"); comp = 1;}

			printf("1st PASSAGE NODE VALUE: %d\n", temp -> value); num++;
		}
	}

	if (num>height) {height = num;}
	m3 -> gen = height; num3++;

	printf("__________________________________________________________________\n\n");
}

void insert2(int n)
{
	printf("\n");
	printf("__________________________________________________________________\n\n");

	if (temp2==NULL)
	{
		m2 = (node*)malloc(sizeof(node)); head2 = m2; temp2 = m2;
		temp2 -> value = input; temp2 -> left = NULL; temp2 -> right = NULL;

		printf("2nd PASSAGE NODE VALUE: %d\n", temp2 -> value); num2++;

		m4 = (ppl*)malloc(sizeof(ppl)); head4 = m4; temp4 = m4;
		m4 -> par = NULL; m4 -> value = temp2 -> value; m4 -> next = NULL;
	}

	else if (temp2!=NULL)
	{
		printf("2nd PASSAGE NODE VALUE: %d\n", temp2 -> value); num2++;

		while (temp4->next!=NULL) {temp4 = temp4 -> next;}
		m4 = (ppl*)malloc(sizeof(ppl));
		temp4 -> next = m4;

		while (comp==0)
		{
			if (input==temp2->value)
			{
				if (temp2->left==NULL)
				{
					m4 -> par = temp2 -> value;
					m2 = (node*)malloc(sizeof(node)); temp2 -> left = m2;
					m2 -> value = input; m2 -> left = NULL; m2 -> right = NULL;
					m4 -> value = temp2 -> value; m4 -> next = NULL;
				}

				else if ((temp2->left!=NULL)&&(temp2->left->value==input)) {temp2 = temp2 -> left;}

				else if ((temp2->left!=NULL)&&(temp2->left->value>input))
				{
					m4 -> par = temp2 -> value;
					m2 = (node*)malloc(sizeof(node));
					m2 -> value = input; m2 -> right = NULL; m2 -> left = temp2 -> left;
					temp2 -> left = m2;
					m4 -> value = temp2 -> value; m4 -> next = NULL;
				}

				comp = 1;
			}

			else if ((input<temp2->value)&&(temp2->right==NULL))
			{
				m4 -> par = temp2 -> value;
				m2 = (node*)malloc(sizeof(node)); m2 -> value = input;
				temp2 -> right = m2; temp2 -> right -> left = NULL; temp2 -> right -> right = NULL;
				temp2 = temp2 -> right; comp = 1;
				m4 -> value = temp2 -> value; m4 -> next = NULL;
			}

			else if ((input<temp2->value)&&(temp2->right!=NULL)) {temp2 = temp2 -> right;}

			else if ((input>temp2->value)&&(temp2->left==NULL))
			{
				m4 -> par = temp2 -> value;
				m2 = (node*)malloc(sizeof(node)); m2 -> value = input;
				temp2 -> left = m2; temp2 -> left -> left = NULL; temp2 -> left -> right = NULL;
				temp2 = temp2 -> left; comp = 1;
				m4 -> value = temp2 -> value; m4 -> next = NULL;
			}

			else if ((input>temp2->value)&&(temp2->left!=NULL)) {temp2 = temp2 -> left;}
			else {printf("\nFatal error code: 1\n\n"); comp = 1;}

			printf("2nd PASSAGE NODE VALUE: %d\n", temp2 -> value); num2++;
		}
	}

	if (num2>height2) {height2 = num2;}
	m4 -> gen = height2; num4++;
	printf("__________________________________________________________________\n\n");
}

void mirror()
{
	int mirror = 1;

	for (int i=0; i<=num3*num3; i++)
	{
		for (int j=1; j<=num3-1; j++)
		{
			if (temp3 -> value > temp3 -> next -> value)
			{
				t = temp3 -> par;
				temp3 -> par = temp3 -> next -> par;
				temp3 -> next -> par = t;

				t = temp3 -> value;
				temp3 -> value = temp3 -> next -> value;
				temp3 -> next -> value = t;

				t = temp3 -> gen;
				temp3 -> gen = temp3 -> next -> gen;
				temp3 -> next -> gen = t;
			}
			temp3 = temp3 -> next;
		}
		temp3 = head3;
	}

	while (temp3->next!=NULL)
	{
		printf("par: %d\nvalue: %d\ngen: %d\nnext: %d\n\n",
			temp3->par, temp3->value, temp3->gen, temp3->next);
		temp3 = temp3 -> next;
	}
	printf("par: %d\nvalue: %d\ngen: %d\nnext: %d\n\n",
			temp3->par, temp3->value, temp3->gen, temp3->next);

	printf("**********************************************************************\n\n");

	for (int i=0; i<=num4*num4; i++)
	{
		for (int j=1; j<=num4-1; j++)
		{
			if (temp4 -> value > temp4 -> next -> value)
			{
				t2 = temp4 -> par;
				temp4 -> par = temp4 -> next -> par;
				temp4 -> next -> par = t2;

				t2 = temp4 -> value;
				temp4 -> value = temp4 -> next -> value;
				temp4 -> next -> value = t2;

				t2 = temp4 -> gen;
				temp4 -> gen = temp4 -> next -> gen;
				temp4 -> next -> gen = t2;
			}
			temp4 = temp4 -> next;
		}
		temp4 = head4;
	}

	while (temp4->next!=NULL)
	{
		printf("par: %d\nvalue: %d\ngen: %d\nnext: %d\n\n",
			temp4->par, temp4->value, temp4->gen, temp4->next);
		temp4 = temp4 -> next;
	}
	printf("par: %d\nvalue: %d\ngen: %d\nnext: %d\n\n",
			temp4->par, temp4->value, temp4->gen, temp4->next);

	while ((temp3->next!=NULL)||(temp4->next!=NULL))
	{
		if ((temp3->par!=temp4->par)||(temp3->value!=temp4->value)||(temp3->gen!=temp4->gen))
			{mirror = 0;}

		temp3 = temp3 -> next; temp4 = temp4 -> next;
	}

	if ((temp3->next==NULL)&&(temp4->next==NULL))
	{
		if ((temp3->par!=temp4->par)||(temp3->value!=temp4->value)||(temp3->gen!=temp4->gen))
			{mirror = 0;}
	}

	else {mirror = 0;}
	(mirror==1) ? printf("The trees are mirrored!\n\n") : printf("The trees are unmirrored.\n\n");
}