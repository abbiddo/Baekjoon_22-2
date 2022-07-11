/**
프로그램명 : 1446.cpp
설명 : 지름길
작성일시 : 2022.07.11
작성자 : 정소영
**/

#include <iostream>
using namespace std;

int arr[12][3];
int dp[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, d, c = 0;   cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    for (int i = 1; i <= d; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j][1] == i) {
                if (dp[i]) dp[i] = min(dp[i], min(dp[arr[j][0]] + arr[j][2], dp[i - 1] + 1));
                else dp[i] = min(dp[arr[j][0]] + arr[j][2], dp[i - 1] + 1);
                c = 1;
            }
        }
        if (!c) dp[i] = dp[i - 1] + 1;
        c = 0;
    }

    cout << dp[d];
}

/**
실행 결과
5 150
0 50 10
0 50 20
50 100 10
100 151 10
110 140 90
-----
70
**/
