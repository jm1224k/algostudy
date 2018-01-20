/*
	input�迭�� ���� �迭�� �ִ´�
	left shift �� �迭���� ans �迭�� �ִ´�.
	�������� d ��ŭ ���� �� i-d �� ������ �� �ְ�
	index�� 0���� �۾����� ���� n�� �����༭ �ڷ� ���� �������.

	�ð����⵵ : O(n)
	�������⵵ : 4byte*n
	*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	vector<int> input(n);
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	for (int i = 0; i < n; ++i) {
		if (i - d < 0) {
			ans[n + (i - d)] = input[i];
		}
		else {
			ans[i - d] = input[i];
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}