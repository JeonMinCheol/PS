#include<iostream>
#include<algorithm>
using namespace std;

long long int N, M, MAX = 1000000000;
long long int* ricecake;

int binary_search(int start, int end) {
	long long int mid = 0 , m;
	while (start <= end) {
		m = 0;
		mid = (start + end) / 2;
		for (long long int i = 0; i < N; i++) {
			if (ricecake[i] > mid) {
				m += ricecake[i] - mid;
			}
		}
		if (m < M) end = mid - 1;
		else if (m > M) start = mid + 1;
		else return mid;
	}
}
int main() {
	cin >> N >> M;
	ricecake = new long long int[N];
	for (int i = 0; i < N; i++) {
		cin >> ricecake[i];
	}
	sort(ricecake, ricecake + N);
	cout << binary_search(0, MAX);
	delete[] ricecake;
	return 0;
}