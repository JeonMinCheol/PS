#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long int n;

int main(void)
{
	cin >> n;
	vector<int>dice;
	int max = 999999 , index;
	for (int i = 0; i < 6; i++) {
		int x;
		cin >> x;
		if (max > x) {
			max = x;
			index = i;
		}
		dice.push_back(x); 
	}
	if (n == 1) {
		int result = 0;
		sort(dice.begin(), dice.end());
		for(int i = 0; i < 5; i++) {
			result += dice[i];
		}
		cout << result;
		return 0;
	}
	int small = max;
	max = 9999999;
	int second_index , middle;
	for (int i = 0; i < 6; i++) {
		if (i == index || 5 - index == i) continue;
		if (max > dice[i]) {
			max = dice[i];
			second_index = i;
		}
	}

	middle = max + small;
	max = 9999999;
	int big;
	for (int i = 0; i < 6; i++) {
		if (i == index || 5 - index == i || i == second_index || 5 - second_index == i) continue;
		if (max > dice[i]) {
			max = dice[i];
		}
	}
	big = max + middle;

	cout << 4 * (static_cast<long long>(big)) + 4 * (2 * n - 3) * (static_cast<long long>(middle)) + (5 * n * n - 16 * n + 12) * static_cast<long long>(small);
	return 0;
}