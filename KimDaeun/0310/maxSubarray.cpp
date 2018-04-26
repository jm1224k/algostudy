// maxSubarray.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

vector <int> maxSubarray(vector <int> arr) {
	// Complete this function
	vector<int> arr_refactored;
	int temp=0;
	int min = -10000;
	//+부터 시작
	while (arr[temp]<0)
	{
		if (arr[temp] > min)
		{
			min = arr[temp];
		}
		temp++;
		if (temp == arr.size())
		{
			vector<int> res = { min,min };
			return res;
		}
	}
	arr_refactored.push_back(arr[temp]);
	int sumArrayMax = arr[temp];
	for (int i = temp+1; i < arr.size(); i++)
	{
		if (arr[i] > 0) sumArrayMax += arr[i];	//subarray를 위한 sum
		//같은 부호면 더함
		if (arr[i - 1] * arr[i] > 0)
		{
			arr_refactored.back() += arr[i];	//마지막 원소에 더함
		}
		//다른부호면 arr_refactored에 추가함
		else
		{
			arr_refactored.push_back(arr[i]);	//제일 뒤에 추가함
		}
	}
	//마지막원소가 음수면 삭제
	if (arr_refactored.back() < 0)
	{
		arr_refactored.pop_back();
	}
	//부분 sum 구해보기
	vector<int> sum;
	sum.push_back(0);
	for (int i = 0; i < arr_refactored.size() - 1; i += 2)
	{
		if (arr_refactored[i] > -arr_refactored[i + 1])
		{
			sum.back() += arr_refactored[i] + arr_refactored[i + 1];
		}
		else
		{
			sum.push_back(0);
		}
		if (i == (arr_refactored.size() - 3))
		{
			sum.back() += arr_refactored[i + 2];
		}
	}
	if (arr_refactored.size() == 1)
	{
		sum[0] = arr_refactored[0];
	}
	//max 구하기
	int result = 0;
	for (int i = 0; i < sum.size(); i++)
	{
		if (sum[i] > result)
		{
			result = sum[i];
		}
	}
	vector<int> subMax;
	subMax.push_back(result);
	subMax.push_back(sumArrayMax);
	return subMax;
}

int main() {
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int arr_i = 0; arr_i < n; arr_i++) {
			cin >> arr[arr_i];
		}
		vector <int> result = maxSubarray(arr);
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << (i != result.size() - 1 ? " " : "");
		}
		cout << endl;


	}
	return 0;
}
