#include <iostream>

int main1()
{
	using namespace std;
	int auks,bats,coots;
	auks = 19.99 + 19.99;
	bats = (int)19.99 + (int)19.99;	//old c syntax
	coots = int(19.99) + int(19.99);	//new c++ syntax
	cout << bats <<endl;
	cout << coots <<endl;
	char ch = 'Z';
	cout << ch <<endl;
	cout << int(ch) <<endl;
	cout << static_cast<int>(ch)<<endl;

	cin.get();
	return 0;
}