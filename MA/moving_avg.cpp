#include <iostream>
#include <list>

using namespace std;

int main()
{
	int m = 3;
	//int arr[7] = { 1000, 4000, 7000, 5500, 9000, 10000, 15000};
	int arr[10] = { 6200, 6500, 6800, 1000, 1100, 1200, 1050, 1042, 1100, 1054};
	int n = sizeof(arr)/sizeof(arr[0]);
	list<int> result;

	int sum = 0;

	for(int i = 0; i < m-1; i++) {
		sum = sum + arr[i];	//m-1까지의 부분sum
	}

	for(int i = m - 1; i < n; i++) {
		sum = sum + arr[i];
		result.push_back(sum/m);
		sum = sum - arr[i-m+1];  
	}

    for (auto &v : arr) {
        cout << v << " ";
    }
    cout << endl;

    cout << "\t  ";
    for (auto &v : result) {
        cout << v << " ";
    }
    cout << endl;
}
