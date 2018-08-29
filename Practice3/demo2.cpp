#include<iostream>
using namespace std;

int main()
{
	long long world;
	long long us;
	cout.setf(ios_base::fixed,ios_base::floatfield);
	cout << "Enter the world's population:________\b\b\b\b\b\b\b\b";
	cin >> world;
	cout << "Enter the us's population:________\b\b\b\b\b\b\b";
	cin >> us;
	cout << us/double(world) <<endl;
	cin.get();
	cin.get();
	return 0;
}