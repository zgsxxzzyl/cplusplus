#include <iostream>
using namespace std;

int main()
{
	cout << "整形:" << endl;
	cout << "bool: " << sizeof(bool) << endl;
	cout << "char: " << sizeof(char) << endl;
	cout << "signed char: " << sizeof(signed char) << endl;
	cout << "unsigned char: " << sizeof(unsigned char) << endl;
	cout << "short: " << sizeof(short) << endl;
	cout << "unsigned short: " << sizeof(unsigned short) << endl;
	cout << "int: " << sizeof(int) << endl;
	cout << "unsigned int: " << sizeof(unsigned int) << endl;
	cout << "long: " << sizeof(long) << endl;
	cout << "unsigned long: " << sizeof(unsigned long) << endl;
	cout << "long long: " << sizeof(long long) << endl;
	cout << "unsigned long long: " << sizeof(unsigned long long) << endl;
	cout << endl;
	cout << "浮点型:" << endl;
	cout << "float: " << sizeof(float) << endl;
	cout << "double: " << sizeof(double) << endl;
	cout << "long double: " << sizeof(long double) << endl;
	cout << endl;
	cout << "wchar_t: " << sizeof(wchar_t) << endl;
	cout << endl;
	cout << "Press any key to exit." << endl;
	cin.get();
	return 0;
}