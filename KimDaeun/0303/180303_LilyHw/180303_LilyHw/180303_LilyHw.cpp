// 180303_LilyHw.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int lilysHomework(vector <int> arr) {
	// Complete this function
	int count = 0;
	int tempIdx = 0;
	int up = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		//min값 넣기
		int temp = arr[i];
		for (int j = i; j < arr.size(); j++)
		{
			if (temp>arr[j])
			{
				temp = arr[j];
				tempIdx = j;
			}
		}
		//
		if (arr[i] != temp)
		{
			count++;
			int temp2 = arr[i];
			arr[i] = temp;
			arr[tempIdx] = temp2;
		}
	}
	up = count;

	//내림차순
	count = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		//max값 넣기
		int temp = arr[i];
		for (int j = i; j < arr.size(); j++)
		{
			if (temp<arr[j])
			{
				temp = arr[j];
				tempIdx = j;
			}
		}
		//
		if (arr[i] != temp)
		{
			count++;
			int temp2 = arr[i];
			arr[i] = temp;
			arr[tempIdx] = temp2;
		}
	}
	if (up > count)
	{
		return count;
	}
	return up;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int arr_i = 0; arr_i < n; arr_i++) {
		cin >> arr[arr_i];
	}
	int result = lilysHomework(arr);
	cout << result << endl;
	return 0;
}