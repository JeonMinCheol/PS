#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, result = 0;
int schedule[10000];
int sorting(int index, int* time, vector<vector<int>>& container1, vector<vector<int>>& container2) {
	int ret = 0;
	queue<int>q;
	q.push(index);
	while (!q.empty()) {
		int top = q.front();
		q.pop();

		// schedule�� value�� ����.
		schedule[top] = 0;
		for (auto elem : container1[top]) schedule[top] = max(schedule[top], schedule[elem]);
		schedule[top] += time[top];
		ret = max(ret, schedule[top]);
		// queue�� ���� �߰�.
		for (auto elem : container2[top]) {
			bool flag = true;
			for (auto a : container1[elem]) {
				if (!schedule[a]) {
					flag = false;
					break;
				}
			}
			if (flag) q.push(elem);
		}

	}
	cout << ret << endl;
	return ret;
}

int main() {
	cin >> n;
	vector<vector<int>>container1(n); // a�� b�� �ϰ� �;��Ѵ�.
	vector<vector<int>>container2(n); // b ������ a�� �� �� �ִ�. (Ž����)

	int time[10000];
	for (int i = 0; i < n; i++) {
		int pre;
		vector<int>elem1;
		cin >> time[i] >> pre;
		for (int j = 0; j < pre; j++) {
			int p;
			cin >> p;
			elem1.push_back(p-1);
			container2[p - 1].push_back(i);
		}
		container1[i] = elem1;
	}

	for (int i = 0; i < n; i++) {
		if (!schedule[i]) result = max(result, sorting(i, time, container1, container2));
	}
	cout << result;
}
