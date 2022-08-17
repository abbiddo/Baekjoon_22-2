/**
프로그램명 : 14501.cpp
설명 : 퇴사
작성일시 : 2022.08.17
작성자 : 정소영
**/

#include <iostream>
using namespace std;

int arr[16][2];
int dp[16];

int main() {
	int n;		cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];

	for (int i = n; i > 0; i--) {
		if (arr[i][0] + i > n + 1) dp[i] = dp[i + 1];
		else dp[i] = max(dp[i + 1], dp[arr[i][0] + i] + arr[i][1]);
	}

	cout << dp[1];
}

/**
실행 결과
7
3 10
5 20
1 10
1 20
2 15
4 40
2 200
-----
45
**/ 
