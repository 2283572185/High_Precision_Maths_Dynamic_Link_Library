#include "../High_Precision_Maths_Dynamic_Link_Library/Operand_Base.h"
#include <iostream>
#include <string>
using namespace std;
using namespace High_Precision_Maths_Library;
int main()
{
    Operand_Base o("3.1415926");
    Operand_Base _o(o);
    string s;
    for (int i = 0; i < 10; i++) {
        o *= _o;
        cout << o.to_string() << "\n";
        cin >> s;
    }
    system("pause");
}
