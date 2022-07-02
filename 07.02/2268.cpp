/**
프로그램명 : 2268.cpp
설명 : 수들의 합7
작성일시 : 2022.07.02
작성자 : 정소영
**/

#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
ll Arr[1000001];
ll* Tree;

ll init(int Node, int start, int end) {
	if (start == end) return Tree[Node] = Arr[start];

	int mid = (start + end) / 2;
	ll left = init(Node * 2, start, mid);
	ll right = init(Node * 2 + 1, mid + 1, end);
	return Tree[Node] = left + right;
}

void update(int Node, int start, int end, int index, ll diff) {
	if (index<start || index>end) return;
	Tree[Node] += diff;

	if (start == end)return;
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

	int n, m, a, b, c;
	cin >> n >> m;

	Tree = new ll[1 << (int)(1 + ceil(log2(n)))];
	init(1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (!a) {
			if (b <= c) cout << sum(1, 0, n - 1, b - 1, c - 1) << "\n";
			else cout << sum(1, 0, n - 1, c - 1, b - 1) << "\n";
		}
		else {
			ll diff = c - Arr[b - 1];
			Arr[b - 1] = c;
			update(1, 0, n - 1, b - 1, diff);
		}
	}
}

/**
실행 결과
3 5
0 1 3
1 1 2
1 2 3
0 2 3
0 1 3
-----
0
3
5
**/
