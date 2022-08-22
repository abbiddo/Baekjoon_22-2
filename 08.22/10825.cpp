/**
프로그램명 : 10825.cpp
설명 : 국영수
작성일시 : 2022.08.22
작성자 : 정소영
**/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef struct {
	string s;
	int a, b, c;
}ss;
ss k[100000];

bool cmp1(ss k1, ss k2) {
	if (k1.a != k2.a) return k1.a > k2.a;
	else {
		if (k1.b != k2.b) return k1.b < k2.b;
		else {
			if (k1.c != k2.c) return k1.c > k2.c;
			else return k1.s < k2.s;
		}
	}
}

int main() {
	int n;		cin >> n;
	for (int i = 0; i < n; i++) cin >> k[i].s >> k[i].a >> k[i].b >> k[i].c;

	sort(k, k + n, cmp1);

	for (int i = 0; i < n; i++) cout << k[i].s << "\n";
}

/**
실행 결과
12
Junkyu 50 60 100
Sangkeun 80 60 50
Sunyoung 80 70 100
Soong 50 60 90
Haebin 50 60 100
Kangsoo 60 80 100
Donghyuk 80 60 100
Sei 70 70 70
Wonseob 70 70 90
Sanghyun 70 70 80
nsj 80 80 80
Taewhan 50 60 90
-----
Donghyuk
Sangkeun
Sunyoung
nsj
Wonseob
Sanghyun
Sei
Kangsoo
Haebin
Junkyu
Soong
Taewhan
**/ 
