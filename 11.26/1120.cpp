/**
프로그램명 : 1120.cpp
설명 : 문자열
작성일시 : 2022.11.26
작성자 : 정소영
**/

#include <iostream>
using namespace std;

int lena, lenb;
void compare(string a, string b) {
	int lena = a.length(), lenb = b.length();
	int mi = lena;
	for (int i = 0; i <= lena - lenb; i++) {
		int cnt = 0;
		for (int j = 0; j < lenb; j++)
			if (a[i + j] != b[j]) cnt++;
		mi = min(mi, cnt);
	}
	cout << mi;
}

int main() {
	string a, b;	cin >> a >> b;
	lena = a.length();
	lenb = b.length();

	if (lena > lenb) compare(a, b);
	else compare(b, a);
}

/**
실행 결과
koder topcoder
-----
1
**/
