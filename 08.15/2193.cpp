/**
프로그램명 : 2193.cpp
설명 : 이친수
작성일시 : 2022.08.15
작성자 : 정소영
**/

#include <iostream>
using namespace std;

long long arr[90] = { 0,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;		cin >> n;

	for (int i = 2; i <= n; i++) arr[i] = arr[i - 1] + arr[i - 2];
	cout << arr[n];
}

/**
실행 결과
3
-----
2
**/ 
