#include<iostream>
int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Enter your name: \n";
	cin.getline(name,ArSize);   //��ȡһ��
	cout << "for " << name <<endl;
	cin.get();
	cin.get();
	return 0;
}