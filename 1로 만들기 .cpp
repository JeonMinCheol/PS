#include<iostream>
using namespace std;
long long int n;
long long int arr[1000001] = { 0, };
int main() {
	cin >> n;
	for (int i = 2; i < n + 1; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1);
		if (i % 2 == 0) arr[i] = min(arr[i], arr[i / 2] + 1);
	}
	cout << arr[n];
}