/**
프로그램명 : 14430.cpp
설명 : 자원캐기
작성일시 : 2022.07.10
작성자 : 정소영
**/

#include <iostream>
using namespace std;

int dp[301][301];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, a;   cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a;
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a) dp[i][j] ++;
        }

    cout << dp[n][m];
}

/**
실행 결과
5 4
0 1 0 0
0 0 1 0
1 1 0 0
1 0 1 0
1 1 0 0
-----
4
**/ 
