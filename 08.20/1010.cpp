/**
프로그램명 : 1010.cpp
설명 : 다리 놓기
작성일시 : 2022.08.20
작성자 : 정소영
**/

#include <iostream>
using namespace std;

int dp[31][31];

int main() {
    for (int i = 1; i < 31; i++) dp[1][i] = i;

    for (int i = 2; i < 31; i++) {
        dp[i][i] = 1;
        for (int j = i + 1; j < 31; j++)
            dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
    }

    int n;  cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;   cin >> a >> b;
        cout << dp[a][b] << endl;
    }
}

/**
실행 결과
3
2 2
1 5
13 29
-----
1
5
67863915
**/ 
