#include "Header_3.h"
#include <iostream>
#include <math.h>
using namespace std;
void scan(int& n, int*& arr) {
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void print(int n_new, int* arr_new) {
	for (int i = 0; i < n_new; i++) {
		cout << arr_new[i] << " ";
	}
}

void create(int n, int& n_new, int* arr, int*& arr_new) {
	int fl = 1;
	n_new = 0;
	int* tmp = new int[n];
	for (int i = 0; i < n; i++) {
		tmp[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i] == tmp[j]) {
				fl = 0;
				break;
			}
		}
		if (fl == 1) {
			tmp[n_new] = arr[i];
			n_new++;
		}
		else
			fl = 1;
	}
	//cout << n_new << " ";
	arr_new = new int[n_new];
	int k = 0;
	for (int i = 0; i < n_new; i++) {
		arr_new[i] = tmp[i];
	}
	delete[] tmp;
}