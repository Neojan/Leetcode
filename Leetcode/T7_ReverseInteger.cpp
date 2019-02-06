#include "leetcode.h"
/*
7. Reverse Integer
https://leetcode.com/problems/reverse-integer/

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [?231,  231 ? 1].
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/


class Solution {
public:
	int reverse(int x) {
		long long ret = 0;//long long can store 
		while (x)
		{
#if 0
			//if use int ret, you need judge it in while
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && x % 10 > 7)) return 0;
			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && x % 10  < -8)) return 0;
#endif		
			ret *= 10;
			ret += x % 10;
			x = x / 10;
		}

		if (ret > ((1 << 31) - 1) || ret < -(1 << 31))
		{
			return 0;
		}

		return ret;
	}
};

void T7_test(void)
{
	Solution t7;
	int test1 = 123;
	int test2 = -123;
	int test3 = 120;
	int test4 = 1534236469;
	int test5 = -1534236469;
	int test6 = 1463847412;
	int ret = 0;

	ret = t7.reverse(test1);
	cout << ret << endl;
	ret = t7.reverse(test2);
	cout << ret << endl;
	ret = t7.reverse(test3);
	cout << ret << endl;
	ret = t7.reverse(test4);
	cout << ret << endl;
	ret = t7.reverse(test5);
	cout << ret << endl;
	ret = t7.reverse(test6);
	cout << ret << endl;

	getchar();
}