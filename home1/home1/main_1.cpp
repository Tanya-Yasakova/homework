#include "function_lib.h"
#include "Header_1.h"
#include <iostream>
void main() {
	int n;
	float* arr;
	scan(n, arr);
	change(n, arr);
	print(n, arr);
	delete[] arr;
}