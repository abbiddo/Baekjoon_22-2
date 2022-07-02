/**
프로그램명 : 10999.cpp
설명 : 구간 합 구하기2
작성일시 : 2022.07.02
작성자 : 정소영
**/

#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
ll* Arr;
ll* Tree;
ll Lazy[4000001]; // 초기값이 0이어야 하므로 동적 할당은 번거로움

ll init(int Node, int start, int end) {
	if (start == end) return Tree[Node] = Arr[start];

	int mid = (start + end) / 2;
	ll left = init(Node * 2, start, mid);
	ll right = init(Node * 2 + 1, mid + 1, end);
	return Tree[Node] = left + right;
}

void lazy_update(int Node, int start, int end) {
	if (Lazy[Node]) {
		Tree[Node] += ((end - start + 1) * Lazy[Node]);
		if (start != end) {
			Lazy[Node * 2] += Lazy[Node];
			Lazy[Node * 2 + 1] += Lazy[Node];
		}
		Lazy[Node] = 0;
	}
}

void update(int Node, int start, int end, int left, int right, ll value) {
	lazy_update(Node, start, end);
	if (right<start || left>end) return;
	if (left <= start && right >= end) {
		Tree[Node] += ((end - start + 1) * value);
		if (start != end) {
			Lazy[Node * 2] += value;
			Lazy[Node * 2 + 1] += value;
		}
		return;
	}	
	
	int mid = (start + end) / 2;
	update(Node * 2, start, mid, left, right, value);
	update(Node * 2 + 1, mid + 1, end, left, right, value);
	Tree[Node] = Tree[Node * 2] + Tree[Node * 2 + 1];
}

ll sum(int Node, int start, int end, int left, int right) {
	lazy_update(Node, start, end);
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

	int n, m, k, a, b, c;  ll d;
	cin >> n >> m >> k;

	Arr = new ll[n];
	Tree = new ll [1 << (int)(1 + ceil(log2(n)))];

	for (int i = 0; i < n; i++) cin >> Arr[i];
	init(1, 0, n - 1);

	for (int i = 0; i < m+k; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(1, 0, n - 1, b - 1, c - 1, d);
		}
		else {
			cin >> b >> c;
			cout << sum(1, 0, n - 1, b - 1, c - 1) << "\n";
		}
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
1 3 4 6
2 2 5
1 1 3 -2
2 2 5
-----
26
22
**/ 
