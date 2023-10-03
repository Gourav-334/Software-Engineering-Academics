#include <iostream>
using namespace std;

int main()
{
	int dec; cout << "Enter the \"decimal\" number: "; cin >> dec;
	int trial = dec, n = 0;

	while (trial != 0) {trial /= 2; n++;}

	int bin[n], m = n-1;

	while (dec != 0) {bin[m] = dec % 2; dec /= 2; m--;}
	cout << "\"Binary\" form: "; for (int i=0; i<n; i++) {cout << bin[i];}

	return 0;
}