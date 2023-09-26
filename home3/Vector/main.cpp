#include <iostream>
#include "Header.h"
using namespace std;

int main() {
	Vector<int> a(3);
	Vector<int> b(3);
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "a = " << a << endl;
	cout << "b = " << b << "\n" << endl;
	cout << "operator+: " << a + b << endl;
	cout << "operator-: " << a - b << endl;
	cout << "operator*: " << a * b << endl;
	cout << "operator==: " << (a == b) << endl;
	cout << "operator!=: " << (a != b) << endl;
	cout << "a.length(): " << a.length() << endl;
	return 0;
}