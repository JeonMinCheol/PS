#include<iostream>
#include<vector>
using namespace std;

int n, m, w;
char output;
vector<int>input; // input.
int subset[55001][2]; // weight, 부호 // subset이 만들어진 시점의 index를 저장하여 subset의 값이 계속해서 갱신되는 것을 방지.
void findWeight(int index) { // 만들 수 있는 모든 무게를 만듦.
	if (index  < n) {
		for (int i = 55000; i > 0; i--) {
			for (int j = 0; j < 2; j++) {
				if (subset[i][j] && subset[i][j] != index + 1) { // subset에 값이 존재하고 이번 인덱스에서 추가된 값이 아닐 경우 실행.

					int val = input[index];
					if (j == 0) { // i가 양수일 때
						subset[i + val][0] = index + 1;
						if (i - val >= 0) {
							subset[i - val][0] = index + 1;
						}
						else {
							subset[-i + val][1] = index + 1;
						}
					}
					else { // i가 음수일 때
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

