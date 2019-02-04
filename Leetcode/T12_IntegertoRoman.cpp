#include "leetcode.h"

/*
T12_IntegertoRoman.cpp
12. Integer to Roman
https://leetcode-cn.com/problems/integer-to-roman/

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
class Solution {
public:
	string intToRoman(int num) {
		string ret;
		int m = 0;

		m = num / (1000);
		pushBack(ret, m, 4);

		m = num % 1000 / 100;
		pushBack(ret, m, 3);

		m = num % 100 / 10;
		pushBack(ret, m, 2);

		m = num % 10 / 1;
		pushBack(ret, m, 1);

		return ret;
	}

	void pushBack(string &ret, int m, int flag);
};

void Solution::pushBack(string &ret, int m, int flag)
{
	char f1 = 0;//main
	char f2 = 0;//mid
	char f3 = 0;//pre

	if (4 == flag)
	{
		f1 = 'M';
	}
	else if (3 == flag)
	{
		f1 = 'C';
		f2 = 'D';
		f3 = 'M';
	}
	else if (2 == flag)
	{
		f1 = 'X';
		f2 = 'L';
		f3 = 'C';
	}
	else
	{
		f1 = 'I';
		f2 = 'V';
		f3 = 'X';
	}

	if (m)
	{
		if (9 == m)
		{
			ret.push_back(f1);
			ret.push_back(f3);
		}
		else if (m > 5 && m < 9)
		{
			ret.push_back(f2);
			for (m; m > 5; m--)
			{
				ret.push_back(f1);
			}
		}
		else if (5 == m)
		{
			ret.push_back(f2);
		}
		else if (4 == m)
		{
			ret.push_back(f1);
			ret.push_back(f2);
		}
		else
		{
			for (m; m > 0; m--)
			{
				ret.push_back(f1);
			}
		}
	}
}

void T12_test(void)
{
	Solution t12;
	string ret;
	
	ret = t12.intToRoman(3);
	cout << ret << endl;

	ret = t12.intToRoman(4);
	cout << ret << endl;

	ret = t12.intToRoman(9);
	cout << ret << endl;

	ret = t12.intToRoman(58);
	cout << ret << endl;

	ret = t12.intToRoman(1994);
	cout << ret << endl;

	ret = t12.intToRoman(3999);
	cout << ret << endl;

	ret = t12.intToRoman(0);
	cout << ret << endl;

	getchar();

}