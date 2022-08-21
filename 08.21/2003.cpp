/**
프로그램명 : 2003.cpp
설명 : 수들의 합2
작성일시 : 2022.08.21
작성자 : 정소영
**/

#include <iostream>
using namespace std;

int arr[10000];

int main() {
    int a, n;   cin >> a >> n;
    
    for (int i = 0; i < a; i++) cin >> arr[i];

    int s = 0, e = 0, cnt = 0;
    int re = 0;
    while (e <= a) {
        if (cnt < n) {
            cnt += arr[e];
            e++;
        }
        else if (cnt > n) {
            cnt -= arr[s];
            s++;
        }
        else {
            re++;
            cnt += arr[e];
            e++;
        }
    }
    cout << re;
}

/**
실행 결과
10 5
1 2 3 4 2 5 3 1 1 2
-----
3
**/ 
