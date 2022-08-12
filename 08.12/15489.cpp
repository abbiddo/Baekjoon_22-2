/**
프로그램명 : 15489.cpp
설명 : 파스칼 삼각형
작성일시 : 2022.08.12
작성자 : 정소영
**/

#include <iostream>
using namespace std;

int arr[31][31];

int main() {
    int r, c, w, re = 0;    cin >> r >> c >> w;
    arr[1][1] = 1;

    for (int i = 2; i < r + w; i++)
        for (int j = 1; j < c + w; j++)
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];

    for (int i = 0; i < w; i++)
        for (int j = 0; j <= i; j++) re += arr[r + i][c + j];

    cout << re;
}

/**
실행 결과
3 1 4
-----
42
**/
