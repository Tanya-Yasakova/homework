#include "function_lib.h"
#include <iostream>
using namespace std;
void scan(int& n, float*& arr) {
	cin >> n;
	arr = new float[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void print(int n, float* arr) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}