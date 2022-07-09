/**
프로그램명 : 2491.cpp
설명 : 수열
작성일시 : 2022.07.09
작성자 : 정소영
**/

#include <iostream>
using namespace std;

int arr[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, cnt = 1, m = 1;  cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 1; i < n; i++) {
        if (arr[i - 1] <= arr[i]) cnt++;
        else {
            m = max(m, cnt);
            cnt = 1;
        }
    }

    m = max(m, cnt);
    cnt = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i - 1] >= arr[i]) cnt++;
        else {
            m = max(m, cnt);
            cnt = 1;
        }
    }

    m = max(m, cnt);
    cnt = 1;

    cout << m;
}

/**
실행 결과
9
4 1 3 3 2 2 9 2 3
-----
4
**/ 
