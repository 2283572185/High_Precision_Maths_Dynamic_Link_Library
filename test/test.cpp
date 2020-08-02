#include "../High_Precision_Maths_Library/Operand.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
using namespace High_Precision_Maths_Library;
int main()
{
    Operand_Standard o('3');
    Operand_Standard _o("-3");
    o += _o;
    cout << o.to_string();
}
