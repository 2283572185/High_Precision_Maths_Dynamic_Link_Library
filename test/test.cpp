#include "../High_Precision_Maths_Dynamic_Link_Library/Operand_Base.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
using namespace High_Precision_Maths_Library;
int main()
{
    Operand_Base o("2");
    Operand_Base _o("2");
    string s;
    OperandStream_Base os;
    clock_t start, finish;
    start = clock();
    change_precision(division, 40);
    change_precision(extraction_of_root, 40);
    change_precision(extraction_of_root_time, 7);
    o &= 3;
    cout << o.to_string() << "\n";
    finish = clock();
    cout << finish - start;
}
