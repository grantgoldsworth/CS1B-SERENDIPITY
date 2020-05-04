#include <iostream>
using namespace std;

int main () {
	
	int num = 10;
	int array[10] = {4, 6, 3, 7, 1, 7, 0, 9, 8, 10};
	
	int smallestIndex;
	int temp;
	
	for (auto i : array) {
		cout << i << "\t";
	}
	cout << endl << endl;
	
	
	for (int i = 0; i < num; i ++) {
		smallestIndex = i;
		
		for (int j = i + 1; j < num; j ++) {
			if (array[j] < array[smallestIndex]) {
				smallestIndex = j;
			}
		} // end inner loop
		
		temp = array[smallestIndex];
		array[smallestIndex] = array[i];
		array[i] = temp;
		
		
	} // end main loop
	
	for (auto i : array) {
		cout << i << "\t";
	}
	cout << endl;
	
	return 0;
}