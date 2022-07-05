/**
프로그램명 : 2448.cpp
설명 : 별 찍기 11
작성일시 : 2022.07.05
작성자 : 정소영
**/

#include <iostream>
using namespace std;

char star[3072][6148];

void stars(int n, int x, int y) {
	if (n == 3) {
		star[y][x] = '*';

		star[y + 1][x - 1] = '*';
		star[y + 1][x + 1] = '*';
		
		star[y + 2][x - 2] = '*';
		star[y + 2][x - 1] = '*';
		star[y + 2][x] = '*';
		star[y + 2][x + 1] = '*';
		star[y + 2][x + 2] = '*';

		return;
	}

	stars(n / 2, x, y);
	stars(n / 2, x - n / 2, y + n / 2);
	stars(n / 2, x + n / 2, y + n / 2);
}

int main() {
	int n;		cin >> n;
	for (int i = 0; i < n; i++) 	star[i][n * 2 - 1] = 0;

	stars(n, n-1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			if (star[i][j] == '*') cout << star[i][j];
			else cout << ' ';
		}
		cout << "\n";
	}
}

/**
실행 결과
3
-----
  *
 * *
*****
**/ 
