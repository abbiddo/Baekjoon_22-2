/**
프로그램명 : 16935.cpp
설명 : 파스칼의 삼각형
작성일시 : 2022.07.09
작성자 : 정소영
**/

#include <iostream>
using namespace std;

int arr[31][31] = { {0}, {0, 1}, {0, 1, 1} };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b;   cin >> a >> b;
    if (b == 1 || a == b) {
        cout << 1; return 0;
    }

    for (int i = 3; i <= a; i++) {
        arr[i][1] = arr[i][i] = 1;
        for (int j = 2; j < i; j++) arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
    }
    cout << arr[a][b];
}

/**
실행 결과
5 3
-----
6
**/ 
