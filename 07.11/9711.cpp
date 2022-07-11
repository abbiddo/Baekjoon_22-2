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

        if (a < 91) cout << "Case #" << i + 1 << ": " << dp[a] % b << "\n";
        else {
            ll tmp = dp[90];   dp[90] %= b;
            ll tmp2 = dp[89]; dp[89] %= b;

            for (ll j = 91; j <= a; j++) dp[j] = (dp[j - 1] + dp[j - 2]) % b;
            cout << "Case #" << i + 1 << ": " << dp[a] << "\n";
            
            dp[90] = tmp;   dp[89] = tmp2;
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
