#include<iostream>
using namespace std;

const int R = 12;

int demo1()
{
	int num;
	cout << "Please enter your number:___\b\b\b";	//\b ÍË¸ñ
	cin >> num;
	cout << "Convert to :" << num*R<<endl;
	cin.get();
	cin.get();
	return 0;
}