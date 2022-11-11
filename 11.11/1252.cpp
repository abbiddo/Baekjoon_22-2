/**
프로그램명 : 1252.cpp
설명 : 이진수 덧셈
작성일시 : 2022.11.11
작성자 : 정소영
**/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string a, b;
vector<int> arr;

void kk(string a, string b) {
    int index = 0, carry = 0, zero = 0;
    for (index; index < a.length(); index++) {
        int sum = a[index] + carry - 48;

        if (index < b.length()) sum += (b[index] - 48);

        if (sum > 1) {
            carry = 1;
            sum -= 2;
        }
        else carry = 0;

        if (sum) zero = 1;

        arr.push_back(sum);
    }

    if (carry) {
        arr.push_back(1);
        zero = 1;
    }

    if (!zero) {
        cout << "0";
        return;
    }

    while (!*(arr.end()-1)) arr.erase((arr.end()-1));

    for (int i = arr.size() - 1; i >= 0; i--) cout << arr[i];
}

int main() {
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (a.length() > b.length()) kk(a, b);
    else kk(b, a);
}

/**
실행 결과
1001101 10010
-----
1011111
**/
