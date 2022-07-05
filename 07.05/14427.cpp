/**
프로그램명 : 14427.cpp
설명 : 수열과 쿠러ㅣ15
작성일시 : 2022.07.05
작성자 : 정소영
**/

#include <iostream>
#include <cmath>
using namespace std;

typedef struct {
	int data;
	int index;
}tree;
int* Arr;
tree Tree[400001];

tree min(tree a, tree b) {
	if (a.data < b.data) return a;
	if (a.data > b.data) return b;
	if (a.index < b.index) return a;
	return b;
}

tree init(int Node, int start, int end) {
	if (start == end) return Tree[Node] = { Arr[start], start };

	int mid = (start + end) / 2;
	tree left = init(Node * 2, start, mid);
	tree right = init(Node * 2 + 1, mid + 1, end);
	return Tree[Node] = min(left, right);
}

void update(int Node, int start, int end, int index, int value) {
	if (index > end || index < start) return;
	if (start == end) {
		Tree[Node] = { value, index };
		return;
	}

	int mid = (start + end) / 2;
	update(Node * 2, start, mid, index, value);
	update(Node * 2 + 1, mid + 1, end, index, value);
	Tree[Node] = min(Tree[Node * 2], Tree[Node * 2 + 1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;		cin >> n;
	Arr = new int[n + 1];
	for (int i = 1; i <= n; i++) cin >> Arr[i];

	init(1, 1, n);

	int m;	cin >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			update(1, 1, n, b, c);
		}
		else cout << Tree[1].index << "\n";
	}
}

/**
실행 결과
5
5 4 3 2 1
5
2
1 5 3
2
1 4 3
2
-----
5
4
3
**/ 
