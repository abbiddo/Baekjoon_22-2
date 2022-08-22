/**
프로그램명 : 15656.cpp
설명 : N과 M7
작성일시 : 2022.08.22
작성자 : 정소영
**/

#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[7];
int list[7];

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << list[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		list[cnt] = arr[i];
		dfs(cnt + 1);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);
	dfs(0);
}

/**
실행 결과
4 2
9 8 7 1
-----
1 1
1 7
1 8
1 9
7 1
7 7
7 8
7 9
8 1
8 7
8 8
8 9
9 1
9 7
9 8
9 9
**/ 
