#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "MovingAverage.h"

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

	MovingAverage* movingAve = new MovingAverage(filter_length);

    int arr[10] = { 6200, 6500, 6800, 1000, 1100, 1200, 1050, 1042, 1100, 1054};

    for (int i = 0; i < 10; i++) {
        movingAve->add(arr[i]);
        cout << movingAve->getCurrentAverage() << " ";
    }
    cout << endl;

    double* my_data = movingAve->getData();
	
    printData(my_data, filter_length);
	
    movingAve->~MovingAverage();
	
    return EXIT_SUCCESS;
}


