#include "../High_Precision_Maths_Library/Operand.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
using namespace High_Precision_Maths_Library;
int main()
{
    Operand_Base o(10);
    Operand_Base _o("1112");
    change_precision(division, 32);
    change_precision(extraction_of_root, 31);
    change_precision(extraction_of_root_time, 7);
    o &= 2;
    cout << o.to_string();
}
