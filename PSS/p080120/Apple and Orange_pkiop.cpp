/*
	cal_position : a�� apple�迭�� ����� ������ ��� ��ġ ��� orange�� ����������
	appleAndOrange : ���� ��ġ�� s�� t ���̿� ������ num�� ������Ű�� ������� ���
	�ð����⵵ O(n) 
	�������⵵ n * 1byte
*/

#include <iostream>
#include <vector>

using namespace std;

vector <int> cal_position(int a, vector<int> fr) {
	vector<int> retn;
	for (int i = 0; i < fr.size(); ++i) {
		retn.push_back(a + fr[i]);
	}
	return retn;
}

vector <int> appleAndOrange(int s, int t, int a, int b, vector <int> apple, vector <int> orange) {
	vector<int> retn(2);
	int num = 0;
	vector<int> fr_re = cal_position(a, apple);
	for (int i = 0; i < fr_re.size(); ++i) {
		if (fr_re[i] >= s && fr_re[i] <= t) {
			num++;
		}
	}
	retn[0] = num;
	num = 0;
	fr_re.clear();
	fr_re = cal_position(b, orange);
	for (int i = 0; i < fr_re.size(); ++i) {
		if (fr_re[i] >= s && fr_re[i] <= t) {
			num++;
		}
	}
	retn[1] = num;
	return retn;
}


int main() {
	int s;
	int t;
	cin >> s >> t;
	int a;
	int b;
	cin >> a >> b;
	int m;
	int n;
	cin >> m >> n;
	vector<int> apple(m);
	for (int apple_i = 0; apple_i < m; apple_i++) {
		cin >> apple[apple_i];
	}
	vector<int> orange(n);
	for (int orange_i = 0; orange_i < n; orange_i++) {
		cin >> orange[orange_i];
	}
	vector <int> result = appleAndOrange(s, t, a, b, apple, orange);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << (i != result.size() - 1 ? "\n" : "");
	}
	cout << endl;


	return 0;
}
