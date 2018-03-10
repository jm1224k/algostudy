#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long           lli;

#define pb push_back


vector < lli > height;
vector < int > s;
lli Histogram(vector<lli> &height)
{
	s.clear();
	height.pb(0);

	lli sum = 0;
	int i = 0;
	while (i < height.size())
	{
		if (s.empty() || height[i] > height[s.back()])
		{
			s.pb(i);
			i++;
		}
		else // i�� �������� �ʾƼ� �ڿ��� ���� ���� stack �� ���� ���� ���ö����� �ݺ��Ѵ�.
		{
			int t = s.back();
			s.pop_back(); // s�� �����ߴ� ������ �ε����� ����. 
			//cout << "first i : " << i << " s.back : " << t << endl;
			sum = max(sum, height[t] * (s.empty() ? i : i - s.back() - 1));
			//cout << "sum : " << sum << endl;
		}
		/*cout << " i : " << i << '\n' << " s : " ;
		for (int i = 0; i < s.size(); ++i) {
			cout << s[i] << ' '; 
		}
		cout << endl;*/
	}

	return sum;
}

int main(void)
{
	int i, j, k, kase = 0;

	int n;
	cin >> n;
	height.assign(n, 0);
	for (i = 0; i<n; i++) 
		scanf_s("%lld", &height[i]);
	printf("%lld\n", Histogram(height));
	
	return 0;
}
