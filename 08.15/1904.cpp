/**
프로그램명 : 1904.cpp
설명 : 01타일
작성일시 : 2022.08.15
작성자 : 정소영
**/

#include <iostream>
using namespace std;

int arr[1000000] = { 0,1,2 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;		cin >> n;

	for (int i = 3; i <= n; i++) arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	cout << arr[n];
}

/**
실행 결과
4
-----
5
**/ 
