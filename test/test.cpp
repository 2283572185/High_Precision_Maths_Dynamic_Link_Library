#include "../High_Precision_Maths_Dynamic_Link_Library/Operand_Base.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
using namespace High_Precision_Maths_Library;
int main()
{
    Operand_Base o("3.1415926535897932384627");
    Operand_Base _o("2");
    string s;
    OperandStream_Base os;
    clock_t start, finish;
    start = clock();
    change_precision(division, 40);
    change_precision(extraction_of_root, 40);
    o %= _o;
    cout << o.to_string() << "\n";
    finish = clock();
    cout << finish - start;
}
