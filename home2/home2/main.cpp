#include "Header.h"
#include <iostream>
using namespace std;

int main() {
	cout << "Create a vector: " << '\n';
	Vector a;
	Vector b;
	a.completion();
	cout << a;
	b.completion();
	cout << b;
	
	cout <<"Sum a+b:  " << a + b << "\n";
	cout << "Subtract:  " << a - b << "\n";
	cout << "Length of a = " << a.GetLength() << "\n";
	cout << "Length of b = " << b.GetLength() << "\n";
	cout << "a scalar* b = " << a*b << '\n';
	cout << "cos = " << a.GetCos(b) << '\n';
	return 0;
}