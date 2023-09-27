#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int>sensor;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sensor.push_back(x);
	}
	sort(sensor.begin(), sensor.end());

	vector<int>range;
	for (int i = 1; i < n; i++) {
		range.push_back(sensor[i] - sensor[i - 1]);
	}
	sort(range.begin(), range.end());

	int result = 0;
	for (int i = 0; i < n - k; i++) {
		result += range[i];
	}
	cout << result;
	return 0;
}