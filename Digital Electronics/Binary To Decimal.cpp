//Time complexity: O(log(n))
//Auxiliary space: O(1)

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int decimal = 0;
	string binary; cout << "Enter \"binary\" number: "; cin >> binary;
	int len = binary.length() - 1;

	for (int i=0; i<binary.length(); i++)
	{
		if (binary[i]=='1') {decimal += (1<<len);}
		len--;
	}

	cout << "\"Decimal\" value is: " << decimal << endl;
	return 0;
}