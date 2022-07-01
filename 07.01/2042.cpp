/**
프로그램명 : 2042.cpp
설명 : 구간 합 구하기
작성일시 : 2022.07.01
작성자 : 정소영
**/

#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
ll* Arr;
ll* Tree;

ll make_tree(int Node, int start, int end) {
	if (start == end) return Tree[Node] = Arr[start];

	int mid = (start + end) / 2;
	ll left = make_tree(Node * 2, start, mid);
	ll right = make_tree(Node * 2 + 1, mid + 1, end);
	return Tree[Node] = left + right;
}

void update(int Node, int start, int end, int index, ll diff) {
	//cout << Tree[Node] << "---전\n";
	if (index<start || index>end) return;
	Tree[Node] += diff;
	//cout << Tree[Node] << "---후\n";

	if (start != end) {
		int mid = (start + end) / 2;
		update(Node * 2, start, mid, index, diff);
		update(Node * 2 + 1, mid + 1, end, index, diff);
	}
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

	int n, m, k, a, b;	ll c;
	cin >> n >> m >> k;

	Arr = new ll[n];
	Tree = new ll [1 << (int)(1 + ceil(log2(n)))];

	for (int i = 0; i < n; i++) cin >> Arr[i];
	make_tree(1, 0, n - 1);

	for (int i = 0; i < m+k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			ll diff = c - Arr[b - 1];
			Arr[b - 1] = c;
			update(1, 0, n - 1, b - 1, diff);
		}
		else cout << sum(1, 0, n - 1, b - 1, c - 1) << "\n";
	}
}

/**
실행 결과
5 2 2
1
2
3
4
5
1 3 6
2 2 5
1 5 2
2 3 5
-----
17
12
**/
