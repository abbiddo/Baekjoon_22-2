/**
프로그램명 : 2357.cpp
설명 : 최솟값과 최댓값
작성일시 : 2022.07.01
작성자 : 정소영
**/

#include <iostream>
#include <cmath>
using namespace std;

int n, m;
int Arr[100001];
int miniTree[4000001];
int maxiTree[4000001];

int make_minitree(int Node, int start, int end) {
	if (start == end) return miniTree[Node] = Arr[start];

	int mid = (start + end) / 2;
	int left = make_minitree(Node * 2, start, mid);
	int right = make_minitree(Node * 2 + 1, mid + 1, end);
	return miniTree[Node] = min(left, right);
}

int make_maxitree(int Node, int start, int end) {
	if (start == end) return maxiTree[Node] = Arr[start];

	int mid = (start + end) / 2;
	int left = make_maxitree(Node * 2, start, mid);
	int right = make_maxitree(Node * 2 + 1, mid + 1, end);
	return maxiTree[Node] = max(left, right);
}

int mini(int Node, int start, int end, int left, int right) {
	if (right < start || left > end) return 1000000001;
	if (left <= start && right >= end) return miniTree[Node];

	int mid = (start + end) / 2;
	int mleft = mini(Node * 2, start, mid, left, right);
	int mright = mini(Node * 2 + 1, mid + 1, end, left, right);
	return min(mleft, mright);
}

int maxi(int Node, int start, int end, int left, int right) {
	if (right < start || left > end) return 0;
	if (left <= start && right >= end) return maxiTree[Node];

	int mid = (start + end) / 2;
	int mleft = maxi(Node * 2, start, mid, left, right);
	int mright = maxi(Node * 2 + 1, mid + 1, end, left, right);
	return max(mleft, mright);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> Arr[i];

	make_minitree(1, 0, n - 1);
	make_maxitree(1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << mini(1, 0, n - 1, a - 1, b - 1) << " " << maxi(1, 0, n - 1, a - 1, b - 1) << "\n";
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
5 100
38 100
20 81
5 81
**/
