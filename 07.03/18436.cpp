/**
프로그램명 : 18436.cpp
설명 : 수열과 리37
작성일시 : 2022.07.03
작성자 : 정소영
**/

#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
typedef struct {
	ll data;
	int cnt;
}tree;

ll* Arr;
tree Tree[400001];

tree init(int Node, int start, int end) {
	if (start == end) {
		if (Arr[start] % 2 == 0) return Tree[Node] = { Arr[start], 1 };
		else return Tree[Node] = { Arr[start],0 };
	}

	int mid = (start + end) / 2;
	tree left = init(Node * 2, start, mid);
	tree right = init(Node * 2 + 1, mid + 1, end);
	return Tree[Node] = { 0,left.cnt + right.cnt };
}

void update(int Node, int start, int end, int index, ll value) {
	if (Arr[index] % 2 && value % 2 || Arr[index] % 2 == 0 && value % 2 == 0) return;
	if (index<start || index>end) return;
	if (start == end) {
		Arr[index] = Tree[Node].data = value;
		if (value % 2 == 0)	Tree[Node].cnt = 1;
		else Tree[Node].cnt = 0;
		return;
	}

	int mid = (start + end) / 2;
	update(Node * 2, start, mid, index, value);
	update(Node * 2 + 1, mid + 1, end, index, value);
	Tree[Node].cnt = Tree[Node * 2].cnt + Tree[Node * 2 + 1].cnt;
}

int eo(int Node, int start, int end, int left, int right) {
	if (right < start || left > end) return 0;
	if (left <= start && right >= end) return Tree[Node].cnt;

	int mid = (start + end) / 2;
	int mleft = eo(Node * 2, start, mid, left, right);
	int mright = eo(Node * 2 + 1, mid + 1, end, left, right);
	return mleft + mright;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b, c, d, k;
	cin >> n;

	Arr = new ll[n];

	for (int i = 0; i < n; i++) cin >> Arr[i];
	init(1, 0, n - 1);

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(1, 0, n - 1, b - 1, c);
		else if (b <= c) k = eo(1, 0, n - 1, b - 1, c - 1);
		else k = eo(1, 0, n - 1, c - 1, b - 1);
		if (a == 2) cout << k << "\n";
		else if (a == 3) cout << abs(c - b) + 1 - k << "\n";
	}
}

/**
실행 결과
6
1 2 3 4 5 6
4
2 2 5
3 1 4
1 5 4
2 1 6
-----
2
2
4
**/
