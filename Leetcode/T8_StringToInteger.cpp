#include "leetcode.h"

/*
T8_StringToInteger.cpp
8. String to Integer (atoi)
https://leetcode-cn.com/problems/string-to-integer-atoi/

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [?231,  231 ? 1]. If the numerical value is out of the range of representable values, INT_MAX (231 ? 1) or INT_MIN (?231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical
digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
Thefore INT_MIN (?231) is returned.
*/

class Solution {
public:
	int myAtoi(string str) {
		int ret = 0;
		int i = 0;
		int nFlag = 1;
		int pop = 0;

		for (; (str[i] == ' ' && i < str.length()); i++);

		if ((i == str.length()) || ((str[i] != '-') && (str[i] != '+') && (str[i] < '0' || str[i] > '9')))
		{
			return 0;
		}

		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
			{
				nFlag = -1;
			}
			++i;
		}

		for (; (str[i] >= '0' && str[i] <= '9'); i++)
		{
			pop = nFlag*(str[i] - '0');
			if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && pop > 7)) return INT_MAX;
			if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && pop < -8)) return INT_MIN;
			ret *= 10;
			ret += pop;
		}

		return ret;
	}
};

void T8_test()
{
	Solution t8;
	int ret = 0;
	string s1("42");
	string s2("   -42");
	string s3("4193 with words");
	string s4("words and 987");
	string s5("-91283472332");
	string s6("9223372036854775808");

	ret = t8.myAtoi(s1);
	cout << ret << endl;

	ret = t8.myAtoi(s2);
	cout << ret << endl;

	ret = t8.myAtoi(s3);
	cout << ret << endl;

	ret = t8.myAtoi(s4);
	cout << ret << endl;

	ret = t8.myAtoi(s5);
	cout << ret << endl;

	ret = t8.myAtoi(s6);
	cout << ret << endl;

	getchar();
}