#include "leetcode.h"
//#include <sstream>

/*
T9_PalindromeNumber.cpp
9. Palindrome Number
https://leetcode-cn.com/problems/palindrome-number/

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

class Solution {
public:
	bool isPalindrome(int x) {
		stringstream stream;
		string temp("");
		int i = 0;
		stream << x;
		stream >> temp;

		int len = temp.length();
		int halfLen = len / 2;

		if (len == 1)
		{
			return true;
		}

		for (; i < halfLen; i++)
		{
			if (temp[i] != temp[len - i - 1])
			{
				return false;
			}
		}
		return true;
	}
};

void T9_test()
{
	Solution t9;
	bool ret = 0;
	int t1 = 10;
	int t2 = 1;
	int t3 = 121;
	int t4 = -121;

	ret = t9.isPalindrome(t1);

	cout << ret << endl;

	ret = t9.isPalindrome(t2);
	cout << ret << endl;

	ret = t9.isPalindrome(t3);
	cout << ret << endl;

	ret = t9.isPalindrome(t4);
	cout << ret << endl;

	getchar();
}