/**
프로그램명 : 11652.cpp
설명 : 카드
작성일시 : 2022.08.16
작성자 : 정소영
**/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long>v;

int main() {
	int n;		cin >> n;
	for (int i = 0; i < n; i++) {
		long long a;	cin >> a;
		v.push_back(a);
	}
	
	sort(v.begin(), v.end());

	long long cnt = 1, re = 1, ma = v[0];

	for (int i = 1; i < v.size(); i++) {
		if (v[i - 1] == v[i]) cnt++;
		else {
			re = max(re, cnt);
			cnt = 1;
		}
		if (re < cnt) ma = v[i - 1];
	}
	cout << ma;
}

/**
실행 결과
3
-1
0
0
-----
0
**/ 
