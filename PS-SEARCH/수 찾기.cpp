#include <iostream>
#include <algorithm>
using namespace std;

long long int a[100000];
long long int b[100000];
int binary_search(int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (a[mid] == target) return 1;
		else if (a[mid] < target) start = mid + 1;
		else end = mid - 1;
	}

	return 0;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a, a + n);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < m; i++) {
		cout << binary_search(b[i], 0, n-1)<<'\n';
	}
	
}