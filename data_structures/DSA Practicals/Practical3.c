#include <stdio.h>
#include <conio.h>

void main()
{
	int len; 
	char exp[len]; 
	int error; 

	int b1,b2,b3; 
	int t1,t2,t3; 

	while (1)
	{
		scanf("%d", &len); scanf("%s", exp);
		error = 0;
		b1 = 0; b2 = 0; b3 = 0;
		t1 = 0; t2 = 0; t3 = 0;

		for (int i=0; i<len; i++)
		{
			if (exp[i]=='{')
			{
				t2 = 0; t3 =0;
				t1 = 1;
				b1++;
			}

			if (exp[i]=='[') 
			{
				t1 = 0; t3 = 0;
				t2 = 1;
				b2++;
			}

			if (exp[i]=='(') 
			{
				t1 = 0; t2 = 0;
				t3 = 1;
				b3++;
			}

			if (exp[i]=='}') 
			{
				t1 = 0;
				if ((t2==1)||(t3==1)) {error = 1;}
				b1--;
			}

			if (exp[i]==']') 
			{
				t2 = 0;
				if ((t1==1)||(t3==1)) {error = 1;}
				b2--;
			}

			if (exp[i]==')') 
			{
				t3 = 0;
				if ((t1==1)||(t2==1)) {error = 1;}
				b3--;
			}
		}

		if ((b1!=0)||(b2!=0)||(b3!=0)) {error = 1;}

		if (error==0) {printf("\nNo errors...\n");}
		else if (error==1) {printf("\nError encountered!\n");}
	}
}