#include <iostream>
#include <time.h>
#include "../High_Precision_Maths_Library/Operand.h"
using namespace std;
using namespace High_Precision_Maths_Library;
int main() {
	int n, m;
	cout << "请分别输入分母和分子：" << endl;
	cin >> m >> n;
	int m0 = m, n0 = n;    //m0和n0保存m和n的原始值
	while (m % n != 0) {
		int temp = m;
		m = n;
		n = temp % n;
	}
	if (m < n) {
		cout << "原分式的最简分式为： " << n0 / n << "/" << m0 / n << endl;
	}
	else
	{
		cout << "原分式的最简分式为： " << m0 / n << "/" << n0 / n << endl;
	}
}