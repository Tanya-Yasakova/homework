#include "Header_3.h"
#include <iostream>
void main() {
	int n;
	int* arr;
	int n_new;
	int* arr_new;
	scan(n, arr);
	create(n, n_new, arr, arr_new);
	print(n_new, arr_new);
	delete[] arr;
}