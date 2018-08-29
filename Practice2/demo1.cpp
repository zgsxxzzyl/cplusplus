#include <iostream>
#include <ostream>
using namespace std;

void d_1();
void d_2();
long d_4();
void d_5();

void d_1()
{
	cout << "my name is zhang" << endl;
	cout << "my address is ..." << endl;
}

void d_2()
{
	long l;
	cout << "Please enter long number" <<endl;
	cin >> l;
	cout << "Ma is "<< l*220 << endl;
	cin.get();
	cin.get();
}

long d_4(long c)
{
	return c*1.8+32.0;
}

void d_5(int a,int b)
{
	cout << a <<":"<<b;
	cin.get();
}
int main()
{
	d_1();
	//d_2();
	cout << d_4(20);
	cin.get();
	d_5(1,2);
}