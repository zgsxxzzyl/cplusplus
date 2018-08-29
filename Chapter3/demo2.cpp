#include <iostream>
#define ZERO 0
#include <climits>

int demo2()
{
	using namespace std;
	short sam = SHRT_MAX;
	unsigned short sue = sam;

	cout << "sam is " << sam <<endl;
	cout << "sue is " << sue <<endl;

	sam = sam +1;
	sue = sue +1;
	cout << "sam is " << sam <<endl;
	cout << "sue is " << sue <<endl;

	sam = ZERO;
	sue = ZERO;
	cout << "sam is " << sam <<endl;
	cout << "sue is " << sue <<endl;

	sam = sam -1;
	sue = sue -1;
	cout << "sam is " << sam <<endl;
	cout << "sue is " << sue <<endl;

	cin.get();
	return 0;
}