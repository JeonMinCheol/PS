#include<iostream>
#include<algorithm>
using namespace std;

int n;
long long int result = 0;
long long int arr[1000][10];
int main() {
	cin >> n;
	fill_n(arr[0], 10000, 1);

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < 10; j++) {
			arr[i][j] = 0;
			for (int k = 0; k <= j; k++) {
				arr[i][j] += arr[i - 1][k];
			}
			arr[i][j] %= 10007;
		}

		if (i == n - 1) {
			for (int j = 0; j < 10; j++) {
				result += arr[i][j];
			}
			result %= 10007;
		}
	}

	if (n == 1) cout << 10;
	else cout << result << "\n";
	
}