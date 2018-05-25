#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int n, b;
	cin >> n;
	vector<int> constructionT(n);
	vector<int> additionalT(n);
	vector<vector<int>> adjList(n);
	vector<int> indegree(n);
	for (int i = 0; i < n; i++)
	{
		cin >> constructionT[i];
		cin >> b;
		while (b != -1)
		{
			adjList[b-1].push_back(i);	//b-1��° �ǹ� �Ǽ� �Ŀ� i�ǹ��� �������ִ�.
			indegree[i]++;	//i�� �Ǽ��ϱ����� �ʿ��� �ǹ� ��(�Է¸�)
			cin >> b;
		}
	}
	queue<int> sortedQ;	//i�� i�ǹ� �Ǽ��� �ʿ��� �ǹ���(�� �ð�)Ȯ���� �ʿ� �������� Q�� �����ִ�.
	for (int i = 0; i < n; i++)
	{
		//�ʿ��� �ǹ��� ���� ��� ������ �߰��ȴ�.
		if (indegree[i] == 0)
			sortedQ.push(i);
	}
	while (!sortedQ.empty())
	{
		//���� ť Ž��
		int size = sortedQ.size();
		for (int j = 0; j < size; j++)
		{
			int cur = sortedQ.front();
			sortedQ.pop();
			indegree[cur]--;
			//next = cur�ǹ��� �ʿ��� �ǹ���
			for(int next : adjList[cur])
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
	}
	for (int i = 0; i < n; i++)
		cout << constructionT[i] + additionalT[i] << endl;
	
	return 0;
}