/**
프로그램명 : 1788.cpp
설명 : 피보나치 수의 확장
작성일시 : 2022.08.17
작성자 : 정소영
**/

#include <iostream>
#include <cmath>
using namespace std;

int arr[1000001] = { 0,1 };

int main() {
	int n;		cin >> n;
	int m = abs(n);

	if (n == 0) cout << 0 << "\n";
	else if (n > 0) cout << 1 << "\n";
	else if (m % 2 == 0) cout << -1 << "\n";
	else cout << 1 << "\n";

	for (int i = 2; i <= m; i++) 
		arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000000;

	cout << arr[m];
}

/**
실행 결과
-7
-----
1
13
**/ 
