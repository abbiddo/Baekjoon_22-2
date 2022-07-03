/**
프로그램명 : 12837.cpp
설명 : 가계부 (Hard)
작성일시 : 2022.07.03
작성자 : 정소영
**/

#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
ll Tree[4000001];

void update(int Node, int start, int end, int index, ll diff) {
	if (index<start || index>end) return;
	Tree[Node] += diff;

	if (start == end) return;
	int mid = (start + end) / 2;
	update(Node * 2, start, mid, index, diff);
	update(Node * 2 + 1, mid + 1, end, index, diff);
}

ll sum(int Node, int start, int end, int left, int right) {
	if (right < start || left > end) return 0;
	if (left <= start && right >= end) return Tree[Node];

	int mid = (start + end) / 2;
	ll mleft = sum(Node * 2, start, mid, left, right);
	ll mright = sum(Node * 2 + 1, mid + 1, end, left, right);
	return mleft + mright;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b;	ll c;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(1, 0, n - 1, b - 1, c);
		else cout << sum(1, 0, n - 1, b - 1, c - 1) << "\n";
	}
}

/**
실행 결과
10 6
1 3 10000
1 4 -5000
1 7 -3000
2 1 10
1 6 35000
2 4 10
-----
2000
27000
**/
