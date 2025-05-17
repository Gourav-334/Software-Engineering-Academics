#include <iostream>
using namespace std;

int main()
{
	int dec; cout << "Enter the \"decimal\" number: "; cin >> dec;
	int trial = dec, n = 0;

	while (trial != 0) {trial /= 8; n++;}

	int oct[n], m = n-1;

	while (dec != 0) {oct[m] = dec % 8; dec /= 8; m--;}
	cout << "\"Octal\" form: "; for (int i=0; i<n; i++) {cout << oct[i];}

	return 0;
}