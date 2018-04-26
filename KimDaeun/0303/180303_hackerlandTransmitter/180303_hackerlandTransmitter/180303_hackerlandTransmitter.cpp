#include <iostream>
#include <vector>

using namespace std;

vector<int> vec[200001];
int num[200001];
bool dfs(int x, int thr){
	num[x] = thr;
	int len = vec[x].size();
	for (int i = 0; i < len; ++i) {
		int temp = vec[x][i];
		if (num[temp] == thr) {
			return false;
		}
		if (num[temp] == 0) {
			dfs(temp,3-thr);
		}
	}
	return true;
}

void numclear()
{
	for (int i = 0; i < 200001; ++i) {
		num[i] = 0;
	}
}

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		int v, e;
		
		numclear();
		cin >> v >> e;
		for (int i = 0; i < e; ++i) {
			int x, y;
			cin >> x >> y;
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		bool ans = true;
		for (int i = 1; i <= v; ++i) {
			if (num[i] == 0) {
				ans = dfs(i, 1);
			}
			if (ans == false) {
				break;
			}
		}
		cout << (ans ? "YES" : "NO") << endl;

	}
}