/**
프로그램명 : 9711.cpp
설명 : 피보나치
작성일시 : 2022.07.11
작성자 : 정소영
**/

#include <iostream>
using namespace std;

typedef long long ll;
ll dp[10001] = { 0,1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 2; i < 91; i++) dp[i] = dp[i - 1] + dp[i - 2];

    int n;  cin >> n;

    for (int i = 0; i < n; i++) {
        ll a, b;   cin >> a >> b;

        // 1번째 수를 구할 때는 아래 반복문이 실행되지 않으므로 나머지 계산이 되지 않음
        // 따로 계산을 해야함
        if (a == 1) cout << "Case #" << i + 1 << ": " << dp[a] % b << "\n";
        else {
            for (int j = 2; j <= a; j++) dp[j] = (dp[j - 1] + dp[j - 2]) % b;
            cout << "Case #" << i + 1 << ": " << dp[a] << "\n";
        }
    }
}

/**
실행 결과
10
5 10
6 25
10 21
32 43
100 100
50 50
25 25
45 67
109 32
128 128
-----
Case #1: 5
Case #2: 8
Case #3: 13
Case #4: 15
Case #5: 75
Case #6: 25
Case #7: 0
Case #8: 19
Case #9: 9
Case #10: 69
**/
