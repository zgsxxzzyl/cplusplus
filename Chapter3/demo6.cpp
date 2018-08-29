#include <iostream>

int demo6()
{
	using namespace std;
	cout.setf(ios_base::fixed,ios_base::floatfield);
	float tub = 10.0 /3.0;
	double mint = 10.0 /3.0;
	const float million = 1.0e6;
	cout << tub <<endl;
	cout << mint <<endl;
	cout << million <<endl;
	cin.get();
	return 0;
}