/**
프로그램명 : 10974.cpp
설명 : 모든 순열
작성일시 : 2022.08.22
작성자 : 정소영
**/

#include <iostream>
using namespace std;

int n, arr[8];
int dp[9];

void dfs(int cnt) {
	if (cnt == n) {
		for (int i = 0; i < n; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!dp[i]) {
			arr[cnt] = i;
			dp[i] = 1;
			dfs(cnt + 1);
			dp[i] = 0;
		}
	}
}

int main() {
	cin >> n;	dfs(0);
}

/**
실행 결과
3
-----
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
**/ 
