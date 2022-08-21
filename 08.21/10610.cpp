/**
프로그램명 : 10610.cpp
설명 : 30
작성일시 : 2022.08.21
작성자 : 정소영
**/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	string s;	cin >> s;
	long long sum = 0;

	for (int i = 0; i < s.size(); i++) {
		v.push_back(s[i] - '0');
		sum += s[i] - '0';
	}
	
	sort(v.begin(), v.end(), greater<int>());

	auto it = v.end();
	it--;

	if (*it != 0) {
		cout << -1;
		return 0;
	}

	if (sum % 3 == 0) for (int i = 0; i < v.size(); i++) cout << v[i];
	else cout << -1;
}

/**
실행 결과
80875542
-----
88755420
**/ 
