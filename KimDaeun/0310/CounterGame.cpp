// CounterGame.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

string counterGame(long n) {
	// Complete this function
	//2의 제곱인지 확인하는 방법
	//1을 뺀 수와 and연산하여 0이나오면 2의 제곱
	long power = pow(2, 31);
	int result = 0;
	while (n != 1)
	{
		result++;
		//result=(result+1)%2;
		if (((n - 1)&n) == 0)
		{
			n = n >> 1;
		}
		else
		{
			long temp = n;
			int idx = 0;
			while (1)
			{
				idx++;
				temp = temp << 1;
				if ((temp & power) == power)
				{
					break;
				}
			}
			n -= pow(2, 31-idx);
		}
	}
	if ((result%2) == 1) return "Louise";
	else return "Richard";
}

int main() {
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++) {
		long n;
		cin >> n;
		string result = counterGame(n);
		cout << result << endl;
	}
	return 0;
}

