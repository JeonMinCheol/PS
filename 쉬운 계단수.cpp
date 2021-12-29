#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;

int main() {
	cin >> n;
	long long int arr[100][10];
	arr[0][0] = 0;
	for (int i = 1; i < 10; i++) {
		arr[0][i] = 1;
	}

	long long int rs = 0;
	for (int i = 1; i < n; i++) {
		arr[i][0] = arr[i - 1][1] % 1000000000;
		arr[i][9] = arr[i - 1][8] % 1000000000;
		if (i == n - 1) rs += (arr[i][0] % 1000000000 + arr[i][9] % 1000000000);
		for (int j = 1; j < 9; j++) {
			arr[i][j] = (arr[i - 1][j - 1] % 1000000000 + arr[i - 1][j + 1] % 1000000000);
			arr[i][j] %= 1000000000;
			if (i == n - 1) {
				rs += arr[i][j];
				rs %= 1000000000;
			}
		}
	}
	cout << rs % 1000000000;
}