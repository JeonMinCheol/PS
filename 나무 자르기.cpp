#include<iostream>
#include<algorithm>
using namespace std;

long long int n, m;
long long int v[1000000];

int binary_search(long long int start, long long int end) {
	long long int height = (start + end) / 2;
	long long int result = 0;
	while (start <= end) {
		long long int length = 0;
		height = (start + end) / 2;
		
		for (long long int i = 0; i < n; i++) {
			if (v[i] > height) length += v[i] - height;
		}
		if (length >= m) {
			start = height + 1;
			result = height;
		}
		else end = height - 1;
	}
	return result;
}
int main() {
	cin >> n >> m;
	for (long long int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v, v + n);

	cout<<binary_search(0, 1000000000);
}