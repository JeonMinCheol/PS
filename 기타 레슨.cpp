#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;

int b_search(vector<int>v, int start, int end) {
	long long int result=0;
	while (start <= end) {
		long long int mid = (static_cast<long long>(start) + end) / 2;
		int temp = m;
		long long int length = 0;
		for (int i = 0; i < n; i++) {
			if (length + v[i] <= mid) length += v[i];
			else {
				temp -= 1;
				length = v[i];
			}
		}
		if (temp <= 0) { start = mid + 1; }
		else if(temp > 0){
			result = mid;
			end = mid - 1;
		}
	}
	return result;
}
int main() {
	cin >> n >> m;
	vector<int>v(n);
	int big = 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (big < v[i]) big = v[i];
	}
	cout << b_search(v, big, 100000);

	return 0;
}