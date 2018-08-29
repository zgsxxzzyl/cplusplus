#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool b_a;
char c_a;
char* pc_a;
const char* pcc_a;
signed char sc_a;
unsigned char uc_a;
short s_a;
unsigned short us_a;
int i_a;
unsigned int ui_a;
long l_a;
unsigned long ul_a;

float f_a;
double d_a;
long double ld_a;

string str_a;

void int_to_char();
void char_to_int();
void char_to_string();
void pchar_to_int();
void pchar_to_string();
void int_to_string();

int demo()
{
	int_to_char();
	char_to_int();
	char_to_string();
	pchar_to_int();
	pchar_to_string();
	int_to_string();
	cin.get();
	return 0;
}
//只支持转换正整数
void int_to_char()
{
	i_a = 1;
	char buffer[65];
	itoa( i_a, buffer, 10);   //10代表i_a是10进制，同理可以用二进制、八进制和十六进制
	c_a = buffer[0];
}

void char_to_int()
{
	c_a = '1';
	i_a = c_a;    //转正对应的ASCII码
	i_a = atoi(&c_a);    //转成对应的值
}

void char_to_string()
{
	c_a = 'a';
	str_a = c_a;
}

void pchar_to_int()
{
	pc_a = "123";
	i_a = atoi(pc_a);
}

//都可以
void int_to_string()    //C11 to_string()
{
	i_a = -111;
	stringstream ss;
	ss << i_a;
	ss >> str_a;
}

void pchar_to_string()
{
	pc_a = "sasdasd";
	str_a = pc_a;
}

void string_to_char()
{
	str_a = "a";
	pcc_a = str_a.c_str();
}

