/*
	38�̸��� ���� �����ϰ� 5�� ������� �ݿø��� �ϴ� ����
	5�̸����� �ݿø� �Ǵ� ��� => 38�̻�, �������� 3,4
	5�̻󿡼� �ݿø� �Ǵ� ��� => 38�̻�, �������� 8,9
	������ ��� ���� �״�� �ٽ� ����

	�ð����⵵ O(len)
	�������⵵ �Է¹��� ���� * 12byte(���� ������ �迭 3��)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(vector <int> grades) {
	vector<int> retn;
	int len = grades.size();
	for (int i = 0; i < len; ++i) {
		int k = grades[i];
		if (k % 10 >= 3 && k % 10 <= 4 && k>=38) {
			retn.push_back((k / 10)*10 + 5);
		}
		else if (k % 10 >= 8 && k % 10 <= 9 && k >= 38) {
			retn.push_back((k / 10) * 10 + 10);
		}
		else {
			retn.push_back(grades[i]);
		}
	}
	return retn;
}

int main() {
	int n;
	cin >> n;
	vector<int> grades(n);
	for (int grades_i = 0; grades_i < n; grades_i++) {
		cin >> grades[grades_i];
	}
	vector <int> result = solve(grades);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << (i != result.size() - 1 ? "\n" : "");
	}
	cout << endl;

	return 0;
}
