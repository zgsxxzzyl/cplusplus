#include <iostream>
#include <climits>

int main()
{
	using namespace std;
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	cout << "int bytes is "<<sizeof(int)<<endl;
	cout << "short bytes is "<<sizeof n_short<<endl;
	cout << "long bytes is "<<sizeof n_long<<endl;
	cout << "long long bytes is "<<sizeof n_llong<<endl;
	cout << "char bytes is "<<sizeof(char)<<endl;
	cout << endl;

	cout << "Max value:"<<endl;
	cout << "int bytes is "<<INT_MAX<<endl;
	cout << "short bytes is "<<SHRT_MAX<<endl;
	cout << "long bytes is "<<LONG_MAX<<endl;
	cout << "long long bytes is "<<LLONG_MAX<<endl;

	cout << "int mininum is " << INT_MIN <<endl;
	cout << "Char max bits is " << CHAR_BIT <<endl;
	cin.get();

	return 0;
}