/**
프로그램명 : 2670.cpp
설명 : 연속부분최대곱
작성일시 : 2022.07.09
작성자 : 정소영
**/

#include <iostream>
using namespace std;

double arr[10001];
double dp[10001];

int main() {
    int n;  cin >> n;
    double m;

    for (int i = 0; i < n; i++) cin >> arr[i];
    dp[0] = arr[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(arr[i], dp[i - 1] * arr[i]);
        m = max(m, dp[i]);
    }

    printf("%.3lf", m);
}

/**
실행 결과
8
1.1
0.7
1.3
0.9
1.4
0.8
0.7
1.4
-----
1.638
**/ 
