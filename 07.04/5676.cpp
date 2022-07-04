/**
프로그램명 : 5676.cpp
설명 : 음주 코딩
작성일시 : 2022.07.04
작성자 : 정소영
**/

#include <iostream>
#include <cmath>
#define MAX 100001
using namespace std;

int Arr[MAX];
int Tree[MAX * 4];

int init(int Node, int start, int end) {
	if (start == end) return Tree[Node] = Arr[start];

	int mid = (start + end) / 2;
	int left = init(Node * 2, start, mid);
	int right = init(Node * 2 + 1, mid + 1, end);
	return Tree[Node] = left * right;
}

int update(int Node, int start, int end, int index, int value) {
	if (index<start || index>end) return Tree[Node];
	if (start == end) return Tree[Node] = value;

	int mid = (start + end) / 2;
	int left = update(Node * 2, start, mid, index, value);
	int right = update(Node * 2 + 1, mid + 1, end, index, value);
	return Tree[Node] = left * right;
}

int mul(int Node, int start, int end, int left, int right) {
	if (right < start || left > end) return 1;
	if (left <= start && right >= end) return Tree[Node];

	int mid = (start + end) / 2;
	int mleft = mul(Node * 2, start, mid, left, right);
	int mright = mul(Node * 2 + 1, mid + 1, end, left, right);
	return mleft * mright;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, b, c, k;		char a;

	while(cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			if (k > 0) Arr[i] = 1;
			else if (k < 0) Arr[i] = -1;
			else Arr[i] = 0;
		}

		init(1, 0, n - 1);

		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			if (a == 'C') {
				if (c > 0) update(1, 0, n - 1, b - 1, 1);
				else if (c < 0) update(1, 0, n - 1, b - 1, -1);
				else update(1, 0, n - 1, b - 1, 0);
			}
			else {
				k = mul(1, 0, n - 1, b - 1, c - 1);
				if (k == 1) cout << "+";
				else if (k == -1) cout << "-";
				else cout << "0";
			}
		}
		cout << "\n";
	}
}

/**
실행 결과
4 6
-2 6 0 -1
C 1 10
P 1 4
C 3 7
P 2 2
C 4 -5
P 1 4
5 9
1 5 -2 4 3
P 1 2
P 1 5
C 4 -5
P 1 5
P 4 5
C 3 0
P 1 5
C 4 -5
C 4 -5
-----
0+-
+-+-0
**/
