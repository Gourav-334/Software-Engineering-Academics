#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int decimal = 0;
	string hex; cout << "Enter \"hex\" number: "; cin >> hex;
	int len = hex.length() - 1;

	for (int i=0; i<hex.length(); i++)
	{
		if (hex[i]=='0') {decimal += 0*pow(16,len);}
		if (hex[i]=='1') {decimal += 1*pow(16,len);}
		if (hex[i]=='2') {decimal += 2*pow(16,len);}
		if (hex[i]=='3') {decimal += 3*pow(16,len);}
		if (hex[i]=='4') {decimal += 4*pow(16,len);}
		if (hex[i]=='5') {decimal += 5*pow(16,len);}
		if (hex[i]=='6') {decimal += 6*pow(16,len);}
		if (hex[i]=='7') {decimal += 7*pow(16,len);}
		if (hex[i]=='8') {decimal += 8*pow(16,len);}
		if (hex[i]=='9') {decimal += 9*pow(16,len);}
		if (hex[i]=='A') {decimal += 10*pow(16,len);}
		if (hex[i]=='B') {decimal += 11*pow(16,len);}
		if (hex[i]=='C') {decimal += 12*pow(16,len);}
		if (hex[i]=='D') {decimal += 13*pow(16,len);}
		if (hex[i]=='E') {decimal += 14*pow(16,len);}
		if (hex[i]=='F') {decimal += 15*pow(16,len);}

		len--;
	}

	cout << "\"Decimal\" value is: " << decimal << endl;
	return 0;
}