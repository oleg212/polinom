#include <stdio.h>
#include <iostream>
#define size 20
using namespace std;



int*  fill(int* arr, int sz) {
	for (int i = 0; i < sz; i++) {
		int r = rand()%20;
		arr[i] = r;
	}
	return arr;
}
void show(int* arr, int sz) {
	for (int i = 0; i < sz; i++) {
		cout << arr[i] << "; ";
	}
	cout << endl;
}
int max_it(int* arr, int sz) {
	int max = 0;
	for (int i = 0; i < sz; i++) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
	
}

int max_recur(int* arr, int sz, int start, int max) {
	if (arr[start] > max) { max = arr[start]; }

	if (start == sz - 1) return max;
	else { 
		start++;
		return max_recur(arr, sz, start, max); 
	}
}


int main() {
	int a[size];
	fill(a, size);
	a[size - 1] = 90;
	show(a, size);

	cout << max_it(a, size)<<endl;
	cout << max_recur(a, size, 0, 0);


	return 0;
}