/**
프로그램명 : 11055.cpp
설명 : 가장 큰 부분 수열
작성일시 : 2022.07.06
작성자 : 정소영
**/

#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + arr[i]);
        sum = max(sum, dp[i]);
    }

    cout << sum;
}

/**
실행 결과
10
1 100 2 50 60 3 5 6 7 8
-----
113
**/ 
