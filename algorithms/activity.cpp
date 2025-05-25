#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;



int main()
{
	cout << "Total pairs: ";
	int n; cin >> n;

	int start, end, count=1;
	pair<int,int> times[n];
    vector<pair<int,int>>times2(n);

	for (int i=0; i<n; i++)
	{
		cout << "Pair " << i+1 << ": ";
		cin >> start >> end;
		times[i] = make_pair(start, end);
	}


	auto then = high_resolution_clock::now();

	for (int i=0; i<n-1; i++)
	{
		if (times[i].second<=times[i+1].first) {count++;}
	}


	cout << "Total possibilities: " << count << endl;


	auto now = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(now - then);
	cout << "Duration: " << duration.count() << " ms" << endl;

	//cout << now - then << endl;
	


	return 0;
}
