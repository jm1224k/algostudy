/*
	���� �Է� ���� ���� �� Ļ�ŷ��� ó����ġ���̸� gap�� ����,
	���� ���� ����� ���� �ʴ´ٸ� gap���� x2-x1�� Ŀ�� ��.
	��������ٰ� �ص� x1==x2�� ������ ����ģ�ٸ� �ᱹ gap���� x2-x1�� Ŀ����.
	while�� gap���� x2-x1�� Ŀ���� �����̹Ƿ� NO
	x2==x1�� �Ǹ� while�� ������ YES

	��ġ�� �ٸ��� �������� ���� ��쿡�� �� while������ �ľ��� �� �����Ƿ�
	�� ���� ���� NO�� ����

	�ð����⵵ O(x2-x1+(v1,v2�߿� ���� ��)) => O(1)
	�������⵵ 5byte?
*/

#include <iostream>
#include <string>

using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
	if (x1 != x2 && v1 == v2) {
		return "NO";
	}
	int gap = x2 - x1;
	
	while (gap >= x2 - x1 && x1 != x2) {
		x1 += v1;
		x2 += v2;
	}
	if (x1 == x2) {
		return "YES";
	}
	else {
		return "NO";
	}
}

int main() {
	int x1;
	int v1;
	int x2;
	int v2;
	cin >> x1 >> v1 >> x2 >> v2;
	string result = kangaroo(x1, v1, x2, v2);
	cout << result << endl;
	return 0;
}
