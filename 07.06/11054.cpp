/**
프로그램명 : 11054.cpp
설명 : 가장 긴 바이토닉 부분 수열
작성일시 : 2022.07.06
작성자 : 정소영
**/

#include <iostream>
using namespace std;

int arr[1001];
int mi[1001];
int ma[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, cnt = 0;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        ma[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i]) ma[i] = max(ma[i], ma[j] + 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        mi[i] = 1;
        for (int j = n - 1; j > i; j--)
            if (arr[j] < arr[i]) mi[i] = max(mi[i], mi[j] + 1);
    }

    for (int i = 0; i < n; i++)
        cnt = max(cnt, mi[i] + ma[i]);

    cout << cnt - 1;
}

/**
실행 결과
10
1 5 2 1 4 3 4 5 2 1
-----
7
**/ 
