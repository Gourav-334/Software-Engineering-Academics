#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int dec = 0;
	int oct; cout << "Enter octal value: "; cin >> oct;

	for (int i=0; oct!=0; i++)
	{
		dec += (oct%10) * pow(8,i);
		oct /= 10;
	}

	cout << "Decimal value: " << dec;
	return 0;
}