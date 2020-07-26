#include "../High_Precision_Maths_Dynamic_Link_Library/Operand_Base.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    Operand_Base o("3.1415926");
    Operand_Base _o(o);
    o = o + _o;
    cout << o.to_string();
}
