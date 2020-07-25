#include <iostream>
#include <string>
using namespace std;
int main() {
	long double original = 2;
	long double a, b, c;
	long double middle;
	short number = 0;
	string s;
	a = 1;
	while (true)
	{
		b = original / a;
		c = original / b;
		middle = (a + b + c) / 3;
		a = middle;
		cout << a;
		number++;
		if (number == 10) {
			number = 0;
			cin >> s;
			if (s == "s") {
				break;
			}
		}
	}
	return 0;
}
