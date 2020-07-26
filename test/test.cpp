#include <iostream>
#include <string>
#include "../High_Precision_Maths_Dynamic_Link_Library/Operand_Base.h"
using namespace std;
using namespace High_Precision_Maths_Library;
int main() {
	Operand_Base o1("3.1415926");
	Operand_Base o2("10");
	decimal_point(o1, o2);
	cout << o1.to_string() << "\n" << o2.to_string() << "\n";
	return 0;
}
