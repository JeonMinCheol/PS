#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int t, n, m;
int B[1001], A[1001];
int lower_bound(vector<int>& arr, int key, int start, int end) {
	int mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (arr[mid] >= key) end = mid;
		else start = mid + 1;
	}

	return end + 1;
}

int upper_bound(vector<int>& arr , int key, int start, int end) {
	int mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (arr[mid] > key) end = mid;
		else start = mid + 1;
	}
	return end + 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> t>>n;
	for (int i = 0; i < n; i++)	cin >> A[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> B[i];
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < n; i++) {
		long long int  sum = 0;
		for (int j = i; j < n; j++) {
			sum += A[j];
			v1.push_back(sum);
		}
	}
	for (int i = 0; i < m; i++) {
		long long int  sum = 0;
		for (int j = i; j < m; j++) {
			sum += B[j];
			v2.push_back(sum);
		}
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(), v2.end());

	int result = 0;
	int size = v1.size(), ssize = v2.size();
	for (int i = 0; i < size; i++) {
		if (v1[i] > t) break;
		result += upper_bound(v2, t - v1[i], 0, ssize - 1) - lower_bound(v2, t - v1[i], 0, ssize - 1);
	}

	cout << result;
}