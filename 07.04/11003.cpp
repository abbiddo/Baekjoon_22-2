/**
프로그램명 : 11003.cpp
설명 : 최솟값 찾기
작성일시 : 2022.07.04
작성자 : 정소영
**/

#include <iostream>
#include <deque>
using namespace std;

int* Arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	Arr = new int[n + 1];
	for (int i = 1; i <= n; i++) cin >> Arr[i];

	deque<pair<int, int>> dq;

	for (int i = 1; i <= n; i++) {
		if (!dq.empty() && dq.front().second < i - m + 1) dq.pop_front();
		while (!dq.empty() && dq.back().first > Arr[i]) dq.pop_back();
		dq.push_back(make_pair(Arr[i], i));
		cout << dq.front().first << " ";
	}
}

/**
실행 결과
12 3
1 5 2 3 6 2 3 7 3 5 2 6
-----
1 1 1 2 2 2 2 2 3 3 2 2
**/ 
