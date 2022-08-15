/**
프로그램명 : 25214.cpp
설명 : 크림 파스타
작성일시 : 2022.08.15
작성자 : 정소영
**/

#include <iostream>
using namespace std;

int arr[200000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, mi, an = 0;		cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	mi = arr[0];

	for (int i = 0; i < n; i++) {
		mi = min(mi, arr[i]);
		an = max(an, arr[i] - mi);
		cout << an << " ";
	}
}

/**
실행 결과
6
50 100 70 110 10 100
-----
0 50 50 60 60 90
**/ 
