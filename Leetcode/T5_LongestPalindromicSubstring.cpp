#include "leetcode.h"

/*
5. Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

class Solution {
public:
	string longestPalindrome(string s) {
		int i = 0;
		int j = 0;
		int k = 0;
		int posS = 0;
		int posE = 0;
		int maxSubLen = 1;
		if ((1 == s.size()) || (0 == s.size()))
		{
			return s;
		}
		for (i = 0; i < s.size() - maxSubLen / 2; i++)
		{
			for (k = i; k < s.size() - 1; k++)
			{
				if (s[k] != s[k + 1])//连续相等
				{
					break;
				}
			}

			k++;

			if (i>0)
			{
				for (j = i - 1; j >= 0 && k < s.size(); j--, k++)
				{
					if (s[j] != s[k])
					{
						break;
					}
				}
				j++;
			}

			if (k - j >= maxSubLen)
			{
				posS = j;
				posE = k;
				maxSubLen = posE - posS;
			}
		}

		return s.substr(posS, maxSubLen);
	}
};

void T5_test()
{
	Solution t5;
	string ret;
	string s1("babad");
	string s2("cbbd");
	string s3("bb");
	string s4("abacab");

	ret = t5.longestPalindrome(s1);
	cout << ret.c_str() << endl;

	ret = t5.longestPalindrome(s2);
	cout << ret.c_str() << endl;

	ret = t5.longestPalindrome(s3);
	cout << ret.c_str() << endl;

	ret = t5.longestPalindrome(s4);
	cout << ret.c_str() << endl;

	getchar();
}