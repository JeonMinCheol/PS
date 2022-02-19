#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int s;
int dp[1001][1001];
int solve() {
	queue<vector<int>>q;
	q.push({ 1,0,0,0,0 });
	dp[1][0] = 0;

	while (!q.empty()) {
		int val = q.front()[0]; // �̸�Ƽ���� ����
		int cnt = q.front()[1];
		int clip = q.front()[2];
		int flag1 = q.front()[3]; // �����ؼ� ����
		int flag2 = q.front()[4]; // �����ؼ� ����
		q.pop();
		
		if (val == s) return dp[s][clip] = cnt;
		//ȭ�鿡 �ִ� �̸�Ƽ���� ��� �����ؼ� Ŭ�����忡 �����Ѵ�.
		if(flag1 != 1) q.push({ val , cnt + 1 , val , 1 , 0 });
		
		//Ŭ�����忡 �ִ� ��� �̸�Ƽ���� ȭ�鿡 �ٿ��ֱ� �Ѵ�.
		if(val + clip <= s) if(dp[val + clip][clip] == -1) q.push({val + clip , cnt + 1 , clip , 0 , 0});

		//ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ��� �����Ѵ�.
		if(val - 1 > 0) if (flag2 != 1) q.push({ val - 1 , cnt + 1 , clip , 0 , 1 }); 

		if (dp[val][clip] == -1) dp[val][clip] = cnt;
		else dp[val][clip] = min(dp[val][clip], cnt);
	}
	return dp[s][0];
}
int main() {
	cin >> s;
	fill_n(&dp[0][0], 1001 * 1001, -1);
	cout << solve();
	return 0;
}