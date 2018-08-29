#include <iostream>

int demo4()
{
	using namespace std;
	char ch;
	int i;
	cout << '$' << endl;
	cin >> ch;
	i = ch;
	cout << "This is character : " << ch << endl;
	cout << "ASCII code Value is " << i << endl;
	cout.put(65); //ÏÔÊ¾Ò»¸ö×Ö·û
	cin.get();
	cin.get();
	return 0;
}