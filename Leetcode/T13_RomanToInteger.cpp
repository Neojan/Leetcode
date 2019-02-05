#include "leetcode.h"

/*
T13_RomanToInteger.cpp
13. Roman to Integer
https://leetcode-cn.com/problems/roman-to-integer/
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
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
class Solution {
public:
	int romanToInt(string s) {
		int ret = 0;
		int i = 0;

		for (i; i < s.length(); i++)
		{
			switch (s[i])
			{
			case 'I':
				if (i < s.length() - 1 )
				{
					if (s[i + 1] == 'V')
					{
						ret += 4;					
						i++;
						break;
					}
					else if (s[i + 1] == 'X')
					{
						ret += 9;
						i++;
						break;
					}
				}
				ret += 1;
				break;
			case 'V':
				ret += 5;
				break;
			case 'X':
				if (i < s.length() - 1)
				{
					if (s[i + 1] == 'L')
					{
						ret += 40;
						i++;
						break;
					}
					else if (s[i + 1] == 'C')
					{
						ret += 90;
						i++;
						break;
					}
				}
				ret += 10;
				break;
			case 'L':
				ret += 50;
				break;
			case 'C':
				if (i < s.length() - 1)
				{
					if (s[i + 1] == 'D')
					{
						ret += 400;
						i++;
						break;
					}
					else if (s[i + 1] == 'M')
					{
						ret += 900;
						i++;
						break;
					}
				}
				ret += 100;
				break;
			case 'D':
				ret += 500;
				break;
			case 'M':
				ret += 1000;
				break;
			default:
				break;
			}
		}
	
		return ret;
	}
};


void T13_test(void)
{
	Solution t12;
	int ret;

	ret = t12.romanToInt("III");
	cout << ret << endl;

	ret = t12.romanToInt("IV");
	cout << ret << endl;

	ret = t12.romanToInt("IX");
	cout << ret << endl;

	ret = t12.romanToInt("LVIII");
	cout << ret << endl;

	ret = t12.romanToInt("MCMXCIV");
	cout << ret << endl;

	getchar();

}