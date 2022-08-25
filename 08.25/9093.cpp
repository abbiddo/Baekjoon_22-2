/**
프로그램명 : 9093.cpp
설명 : 단어 뒤집기
작성일시 : 2022.08.25
작성자 : 정소영
**/

#include <iostream>
#include <string>
using namespace std;

int main() {
	nt n;		cin >> n;
	cin.ignore();

	for (int k = 0; k < n; k++) {
		string str;	getline(cin, str);
		int s = 0, e = 0;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ') {
				e = i - 1;
				for (int j = e; j >= s; j--) cout << str[j];
				cout << " ";
				s = i + 1;
			}
		}
		for (int i = str.size() - 1; i >= s; i--) cout << str[i];
		cout << "\n";
	}
}

/**
실행 결과
2
I am happy today
We want to win the first prize
-----
I ma yppah yadot
eW tnaw ot niw eht tsrif ezirp
**/ 
