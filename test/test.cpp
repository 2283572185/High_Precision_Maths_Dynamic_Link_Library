#include "../High_Precision_Maths_Library/Operand.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
using namespace High_Precision_Maths_Library;
int main()
{
    clock_t start, finish;
    Operand_Standard o("3.1415926");
    Operand_Standard _o(o);
    change_precision(division, 20);
    change_precision(extraction_of_root_time, 7);
    start = clock();
    o = o ^ 3;
    finish = clock();
    cout << o.to_string() << "\n";
    cout << finish - start;
}
