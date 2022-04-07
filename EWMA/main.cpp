#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Ema.h"
#include "EmaT.h"
#include "Ewma.h"
#include "EwmaT.h"

using namespace std;

void printData(double *dt, size_t length) {
	cout << "[ ";
	for (size_t i = 0; i < length; i++) {
		cout << dt[i] << " ";
	}
	cout << "]" << endl;
}

void test1() {
    size_t filter_length = 3;

    Ewma *ewma = new Ewma(0.01);
    Ewma *ewma2 = new Ewma(0.5);

    int arr[10] = { 6200, 6500, 6800, 1000, 1100, 1200, 1050, 1042, 1100, 1054};

    for (int i = 0; i < 10; i++) {
        cout << ewma->filter(arr[i]) << " ";
        printf("%.0f ", ewma->filter(arr[i]));
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        cout << ewma2->filter(arr[i]) << " ";
    }
    cout << endl;
}

#define SIZE 50

void test2() {
    size_t filter_length = 3;
    
    // Roughly said, if you set alpha to, let's say, 
    // 0.1 it means that the result will be approximately the average of the last 10 readings.

    Ewma *ewma = new Ewma(0.1); // Less smoothing - faster to detect changes, but more prone to noise
    //Ewma *ewma = new Ewma(0.01); // More smoothing - less prone to noise, but slower to detect changes

    int arr[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                      11, 10, 13, 14, 12, 12, 10, 8, 9, 10,
                      11, 15, 12, 14, 12, 12, 10, 11, 10, 10,
                      47, 48, 45, 42, 45, 47, 50, 51, 47, 50,
                      50, 48, 45, 42, 45, 47, 50, 51, 47, 52
                   };

    printf("Ewma result\n");
    for (int i = 0; i < SIZE; i++) {
        if (i % 10 == 9) {
            printf("\n");
        }
        printf("%.2f ", ewma->filter(arr[i]));
    }
    printf("\n");
}

void test3() {
    size_t filter_length = 3;
    
    // Roughly said, if you set alpha to, let's say, 
    // 0.1 it means that the result will be approximately the average of the last 10 readings.
    
    EwmaT<size_t> *ewma = new EwmaT<size_t>(5, 10); // Less smoothing - faster to detect changes, but more prone to noise
    //Ewma *ewma = new Ewma(0.01, 10); // More smoothing - less prone to noise, but slower to detect changes

    int arr[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                      11, 10, 13, 14, 12, 12, 10, 8, 9, 10,
                      11, 15, 12, 14, 12, 12, 10, 11, 10, 10,
                      47, 48, 45, 42, 45, 47, 50, 51, 47, 50,
                      50, 48, 45, 42, 45, 47, 50, 51, 47, 52
                   };

    printf("EwmaT result\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%lu ", ewma->filter(arr[i]));
        if (i % 10 == 9) {
            printf("\n");
        }
    }
    printf("\n");
}

void test4() {
    Ema * ema = new Ema(0.2);

    double arr[10] = { 1, 0, 0, 0.5, 1, 0.5, 0, 0, 1, 1};

    printf("Ema result\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", ema->filter(arr[i]));
        if (i % 10 == 9) {
            printf("\n");
        }
    }
    printf("\n");
}

void test5() {
    EmaT<int> * ema = new EmaT<int>(20, 100);

    int arr[10] = { 100, 0, 0, 50, 100, 50, 0, 0, 100, 100 };

    printf("EmaT result\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", ema->filter(arr[i]));
        if (i % 10 == 9) {
            printf("\n");
        }
    }
    printf("\n");
}

int main(void) {
    //test1();
    //test2();
    //test3();
    test4();
    test5();

    return EXIT_SUCCESS;
}
