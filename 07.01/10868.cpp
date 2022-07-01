/**
프로그램명 : 10868.cpp
설명 : 최솟값
작성일시 : 2022.07.01
작성자 : 정소영
**/

#include <iostream>
#include <cmath>
using namespace std;

int n, m;
int Arr[100001];
int Tree[4000001];

int make_tree(int Node, int start, int end) {
	if (start == end) return Tree[Node] = Arr[start];

	int mid = (start + end) / 2;
	int left = make_tree(Node * 2, start, mid);
	int right = make_tree(Node * 2 + 1, mid + 1, end);
	return Tree[Node] = min(left, right);
}

int mini(int Node, int start, int end, int left, int right) {
	if (right < start || left > end) return 1000000001;
	if (left <= start && right >= end) return Tree[Node];

	int mid = (start + end) / 2;
	int mleft = mini(Node * 2, start, mid, left, right);
	int mright = mini(Node * 2 + 1, mid + 1, end, left, right);
	return min(mleft, mright);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> Arr[i];

	make_tree(1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << mini(1, 0, n - 1, a - 1, b - 1) << "\n";
	}
}

/**
실행 결과
10 4
75
30
100
38
50
51
52
20
81
5
1 10
3 5
6 9
8 10
-----
5
38
20
5
**/
