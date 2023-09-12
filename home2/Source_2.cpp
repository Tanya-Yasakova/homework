#include "Header_2.h"
#include <iostream>
#include <math.h>
using namespace std;
void scan(int& n, float*& arr) {
	while (true)
	{
		cin >> n;
		if (n % 2 == 0) {
			break;
		}
		else {
			cout << "The number of elements in the array must be even, enter again: ";
		}
	}
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

void change_2(int n, float* arr) {
	float tmp;
	for (int i = 0; i < (n / 2); i++) {
		tmp = arr[i];
		arr[i] = arr[n / 2 + i];
		arr[n / 2 + i] = tmp;
	}
}