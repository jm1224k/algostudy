#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int t, n, k, w;
	int a, b;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		vector<int> constructionT(n);
		vector<int> additionalT(n);
		vector<vector<int>> adjList(n);
		vector<int> indegree(n);
		for (int i = 0; i < n; i++)
		{
			cin >> constructionT[i];
		}
		while (k--)
		{
			cin >> a >> b;
			adjList[a - 1].push_back(b - 1);
			indegree[b - 1]++;
		}
		cin >> w;
		queue<int> sortedQ;
		for (int i = 0; i < n; i++)
		{
			//�ʿ��� �ǹ��� ���� ��� ������ �߰��ȴ�.
			if (indegree[i] == 0)
				sortedQ.push(i);
		}
		//w�ǹ��� �������� �ʿ��� �ǹ����� ���������ʰų�
		//sorting�� ������ while Ż��
		while (indegree[w - 1] && !sortedQ.empty())
		{
			int cur = sortedQ.front();
			sortedQ.pop();
			indegree[cur]--;
			for (int next : adjList[cur])
			{
				indegree[next]--;	//cur�ǹ� �ð� ����
				if (indegree[next] == 0)	//�� �ʿ��� �ǹ��� �������
					sortedQ.push(next);
				int curNeedT = constructionT[cur] + additionalT[cur];
				//cur �Ǽ��ð��� next�� �߰��Ǽ��ð����� ũ�� next �߰��Ǽ��ð��� cur �Ǽ��ð��̵ȴ�.
				if (curNeedT > additionalT[next])
					additionalT[next] = curNeedT;
			}
		}
		cout << constructionT[w - 1] + additionalT[w - 1] << endl;
	}

	return 0;
}