#include "../High_Precision_Maths_Library/Operand.h"
#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
using namespace std;
using namespace High_Precision_Maths_Library;
int main()
{
	// 读取数据
	ifstream f;
	f.open("History.log", ios::in | ios::_Noreplace);
	string s;
	while (!f.eof())
	{
		getline(f, s);
		cout << s;
	}
	f.close();
}