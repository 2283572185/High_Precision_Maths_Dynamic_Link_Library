#include "../High_Precision_Maths_Library/Operand_Standard.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
using namespace High_Precision_Maths_Library;
int main()
{
    clock_t start, finish;
    start = clock();
    Operand_Standard o("-1");
    finish = clock();
    cout << o.to_string() << '\n';
    cout << finish - start;
}
