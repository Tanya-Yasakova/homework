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

	n_new = 1;
	for (int i = 1; i < n; i++) {
		int fl = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				fl = 0;
				break;
			}
		}
		if (fl == 1) {
			n_new++;                                                                                      
		}
	}
	arr_new = new int[n_new];
	arr_new[0] = arr[0];
	int k = 1;
	for (int i = 1; i < n; i++) {
		int fl = 1;
		for (int j = 0; j < i; j++) {
			if  (arr[i] == arr[j]) {
				fl = 0;
				break;
			}
		}
		if (fl == 1) {
			arr_new[k] = arr[i];
			k++;
		}
	}
}