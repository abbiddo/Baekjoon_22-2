/**
프로그램명 : 5893.cpp
설명 : 17배
작성일시 : 2022.08.18
작성자 : 정소영
**/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	string n;	cin >> n;
	string m = n + "0000";
	n = "0000" + n;
	int check = 0;
	vector<int> re;

	for (int i = 0; i < n.size(); i++) n[i] -= '0';
	for (int i = 0; i < m.size(); i++) m[i] -= '0';

	// 16배 + 1배 => 4칸 점프 후 1배 더하기
	for (int i = n.size() - 1; i >= 0;  i--) {
		if (n[i] + m[i] + check == 3) {
			re.push_back(1);
			check = 1;
		}
		else if (n[i] + m[i] + check == 2) {
			re.push_back(0);
			check = 1;
		}
		else {
			re.push_back(n[i] + m[i] + check);
			check = 0;
		}
	}
	if (check == 1) cout << 1;
	for (int i = re.size() - 1; i >= 0; i--) cout << re[i];
}

/**
실행 결과
10110111
-----
110000100111
**/ 
