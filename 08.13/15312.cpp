/**
프로그램명 : 15312.cpp
설명 : 이름 궁합
작성일시 : 2022.08.13
작성자 : 정소영
**/

#include <iostream>
#include <string>
using namespace std;

int alpha[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
int arr[4001];

int main() {
    string a, b;    cin >> a >> b;
    
    for (int i = 0; i < a.size() * 2; i += 2) arr[i] = alpha[a[i / 2] - 'A'];
    for (int i = 0; i < b.size() * 2; i += 2) arr[i+1] = alpha[b[i / 2] - 'A'];

    for (int i = 1; i < a.size() + b.size() - 1; i++)
        for (int j = 0; j < a.size() + b.size() - i; j++)
            arr[j] = (arr[j] + arr[j + 1]) % 10;

    cout << arr[0] << arr[1];
}

/**
실행 결과
CJM
HER
-----
99
**/
