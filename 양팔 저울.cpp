#include<iostream>
#include<vector>
using namespace std;

int n, m, w;
char output;
vector<int>input; // input.
int subset[55001][2]; // weight, ��ȣ // subset�� ������� ������ index�� �����Ͽ� subset�� ���� ����ؼ� ���ŵǴ� ���� ����.
void findWeight(int index) { // ���� �� �ִ� ��� ���Ը� ����.
	if (index  < n) {
		for (int i = 55000; i > 0; i--) {
			for (int j = 0; j < 2; j++) {
				if (subset[i][j] && subset[i][j] != index + 1) { // subset�� ���� �����ϰ� �̹� �ε������� �߰��� ���� �ƴ� ��� ����.

					int val = input[index];
					if (j == 0) { // i�� ����� ��
						subset[i + val][0] = index + 1;
						if (i - val >= 0) {
							subset[i - val][0] = index + 1;
						}
						else {
							subset[-i + val][1] = index + 1;
						}
					}
					else { // i�� ������ ��
						subset[i + val][1] = index + 1;
						if (-i + val >= 0) {
							subset[-i + val][0] = index + 1;
						}
						else {
							subset[i - val][1] = index + 1;
						}
					}
				}
			}
		}
		subset[input[index]][0] = index + 1;
		subset[input[index]][1] = index + 1;
		findWeight(index + 1);
	}
	
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		input.push_back(x);
	} cin >> m;
	findWeight(0);

	while (m--) {
		cin >> w;
		if (subset[w][0]) cout << 'Y' << " ";
		else cout << 'N' << " ";
	}
}

