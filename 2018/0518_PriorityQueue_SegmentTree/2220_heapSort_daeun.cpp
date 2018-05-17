#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
vector<int> heap;
int num_swap;
int cur_size;
void push_heap(int newVal)
{
	heap.push_back(newVal+1);
	int idx = heap.size() - 1;
	int idx_p = (idx - 1) / 2;
	//1�� ���� �ڿ� �־���Ѵ�.
	if (heap[cur_size] != 1 && cur_size>0)
	{
		swap(heap[cur_size - 1], heap[cur_size]);
		num_swap++;
		idx= heap.size() - 2;
		idx_p = (idx - 1) / 2;
	}
	//�ִ� �� ��Ģ������Ű��! (�ڽĺ��� �θ� �� ū ���� ��������)
	while (idx > 0 && heap[idx_p] < heap[idx])
	{
		swap(heap[idx], heap[idx_p]);
		num_swap++;
		idx = idx_p;
		idx_p = (idx - 1) / 2;
	}
}
/*void pop_heap()
{
	heap[0] = heap.back();
	heap.pop_back();
	int cur = 0;
	while (1)
	{
		int left = cur * 2 + 1;
		int right = cur * 2 + 2;
		if (left >= heap.size()) break;
		int next = cur;
		if (heap[next] < heap[left]) next = left;
		//left, right�߿��� �� ū�ʰ� swap
		if (right < heap.size() && heap[next] < heap[right]) next = right;
		//�ڽĵ麸�� ū���̸� break
		if (next == cur) break;
		swap(heap[cur], heap[next]);
		cur = next;
	}
}*/
int main()
{
	int n, a, b = 0;
	cin >> n;
	num_swap = 0;
	cur_size = 0;
	while (n--)
	{
		push_heap(cur_size);
		cur_size++;
	}
	for (int i = 0; i < cur_size; i++)
	{
		cout << heap[i] << " ";
	}
	cout << endl;
	//priority_queue<int, vector<int>, less<int>> maxHeap;
	
	return 0;
}
