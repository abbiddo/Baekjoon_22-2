/**
프로그램명 : 1275.cpp
설명 : 커피숍2
작성일시 : 2022.07.03
작성자 : 정소영
**/

#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
ll* Arr;
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

	int n, m, a, b, c, d;
	cin >> n >> m;

	Arr = new ll[n];
	Tree = new ll[1 << (int)(1 + ceil(log2(n)))];

	for (int i = 0; i < n; i++) cin >> Arr[i];
	init(1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c >> d;
		if (a <= b) cout << sum(1, 0, n - 1, a - 1, b - 1) << "\n";
		else cout << sum(1, 0, n - 1, b - 1, a - 1) << "\n";
		ll diff = d - Arr[c - 1];
		Arr[c - 1] = d;
		update(1, 0, n - 1, c - 1, diff);
	}
}

/**
실행 결과
5 2
1 2 3 4 5
2 3 3 1
3 5 4 1
-----
5
10
**/
