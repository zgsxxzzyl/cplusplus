#include <iostream>
#include "source.h"
#include <cmath>
#include <cstdlib>

int demo1()
{
	using namespace std;
	cout << "------------------part 1"<<endl;
	cout << "Hello world!"<<endl;	//start a new line
	cout << "Hello world! \n";  //start a new line

	cout << "------------------part 2"<<endl;
	int i;  //局部变量声明  栈内存
	i = 100;  //初始化局部变量	堆内存
	cout << i <<endl;

	cout << "------------------part 3"<<endl;
	double area = 6.25;
	double side = sqrt(area);
	cout << side <<endl;

	cout << "------------------part 4"<<endl;
	int ran = rand();
	int ran1 = rand();
	cout << ran <<endl;
	cout << ran1 <<endl;
	return 0;
}

void demo1_d(int n){
	using namespace std;
	cout << "Get int " << n << endl;
	return;
}

void demo1(int n)
{
	return;
}