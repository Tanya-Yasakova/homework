#include "function_lib.h"
#include "Header_2.h"
#include <iostream>
void main() {
	int n;
	float* arr;
	scan(n, arr);
	change_2(n, arr);
	print(n, arr);
	delete[] arr;
}