/**
프로그램명 : 14494.cpp
설명 : 다이나믹이 뭐예요?
작성일시 : 2022.07.10
작성자 : 정소영
**/

#include <iostream>
using namespace std;

long long dp[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;   cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (i == 1 || j == 1) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % 1000000007;
        }

    cout << dp[n][m];
}

/**
실행 결과
1000 1000
-----
910657857
**/ 
