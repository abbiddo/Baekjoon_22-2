/**
프로그램명 : 14428.cpp
설명 : 수열과 쿼리16
작성일시 : 2022.07.02
작성자 : 정소영
**/

#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
typedef struct {
	ll data;
	int index;
}tree;
ll* Arr;
tree Tree[400002];

tree min(tree a, tree b) {
	if (a.data < b.data) return a;
	if (a.data == b.data)
		if (a.index < b.index) return a;
	return b;
}
void init(int Node, int start, int end) {
	if (start == end) {
		Tree[Node] = { Arr[start],start };
		return;
	}

	int mid = (start + end) / 2;
	init(Node * 2, start, mid);
	init(Node * 2 + 1, mid + 1, end);
	Tree[Node] = min(Tree[Node * 2], Tree[Node * 2 + 1]);
}

void update(int Node, int start, int end, int index, ll value) {
	if (index<start || index>end) return;
	if (start == end) {
		Tree[Node] = { value, index };
		return;
	}

	int mid = (start + end) / 2;
	update(Node * 2, start, mid, index, value);
	update(Node * 2 + 1, mid + 1, end, index, value);
	Tree[Node] = min(Tree[Node * 2], Tree[Node * 2 + 1]);
}

tree mini(int Node, int start, int end, int left, int right) {
	if (right < start || left > end) return { 1000000001, 1000000001 };
	if (left <= start && right >= end) return Tree[Node];
	
	int mid = (start + end) / 2;
	return min(mini(Node * 2, start, mid, left, right),
					 mini(Node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b, c;
	cin >> n;
	
	Arr = new ll[n];

	for (int i = 0; i < n; i++) cin >> Arr[i];
	init(1, 0, n - 1);

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(1, 0, n - 1, b - 1, c);
		else cout << mini(1, 0, n - 1, b - 1, c - 1).index + 1 << "\n";
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
4
4
3
**/
