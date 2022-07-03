  /**
프로그램명 : 14438.cpp
설명 : 수열과 쿼리17
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
	return Tree[Node] = min(left, right);
}

void update(int Node, int start, int end, int index, ll value) {
	if (index<start || index>end) return;
	if (start == end) {
		Tree[Node] = value;
		return;
	}

	int mid = (start + end) / 2;
	update(Node * 2, start, mid, index, value);
	update(Node * 2 + 1, mid + 1, end, index, value);
	Tree[Node] = min(Tree[Node * 2], Tree[Node * 2 + 1]);
}

ll mini(int Node, int start, int end, int left, int right) {
	if (right < start || left > end) return 1000000001;
	if (left <= start && right >= end) return Tree[Node];

	int mid = (start + end) / 2;
	ll mleft = mini(Node * 2, start, mid, left, right);
	ll mright = mini(Node * 2 + 1, mid + 1, end, left, right);
	return min(mleft, mright);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b, c, d;
	cin >> n;

	Arr = new ll[n];
	Tree = new ll[1 << (int)(1 + ceil(log2(n)))];

	for (int i = 0; i < n; i++) cin >> Arr[i];
	init(1, 0, n - 1);

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(1, 0, n - 1, b - 1, c);
		else if (b <= c) cout << mini(1, 0, n - 1, b - 1, c - 1) << "\n";
		else cout << mini(1, 0, n - 1, c - 1, b - 1) << "\n";
	}
}

/**
실행 결과
5
5 4 3 2 1
6
2 1 3
2 1 4
1 5 3
2 3 5
1 4 3
2 3 5
-----
3
2
2
3
**/
