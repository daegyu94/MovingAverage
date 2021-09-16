#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Ewma.h"

using namespace std;

void printData(double *dt, size_t length)
{
	cout << "[ ";
	for (size_t i = 0; i < length; i++) {
		cout << dt[i] << " ";
	}
	cout << "]" << endl;
}

int main(void) 
{
    size_t filter_length = 3;

    Ewma *ewma = new Ewma(0.01);
    Ewma *ewma2 = new Ewma(0.5);

    int arr[10] = { 6200, 6500, 6800, 1000, 1100, 1200, 1050, 1042, 1100, 1054};

    for (int i = 0; i < 10; i++) {
        cout << ewma->filter(arr[i]) << " ";
    }
    cout << endl;
	
    for (int i = 0; i < 10; i++) {
        cout << ewma2->filter(arr[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
