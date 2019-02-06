#include "leetcode.h"

/*
T14_LongestCommonPrefix.cpp
14. Longest Common Prefix
https://leetcode-cn.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int i = 0;
		int j = 0;		
		string ret = "";

		if (0 == strs.size())
		{
			return ret;
		}
		if (1 == strs.size())
		{
			return strs[0];
		}

		int minStrLen = strs[0].length();
		for (i = 1; i < strs.size(); i++)
		{
			if (strs[i].length() < minStrLen)
			{
				minStrLen = strs[i].length();
			}
		}
		
		for (j = 0; j < minStrLen; j++)
		{
			for (i = 1; i < strs.size(); i++)
			{
				if (strs[0][j] != strs[i][j])
				{
					return ret;
				}
				else if (strs.size()-1 == i)
				{
					ret.push_back(strs[0][j]);
				}
			}
		}

		return ret;
	}
};


void T14_test(void)
{
	Solution t14;
	string ret;
	vector<string> strs1{ "flower", "flow", "flight" };
	vector<string> strs2{ "", "", "" };
	vector<string> strs3{};
	vector<string> strs4{"a"};
	vector<string> strs5{ "aca", "cba"};

	ret = t14.longestCommonPrefix(strs1);
	cout << ret << endl;
	ret = t14.longestCommonPrefix(strs2);
	cout << ret << endl;
	ret = t14.longestCommonPrefix(strs3);
	cout << ret << endl;
	ret = t14.longestCommonPrefix(strs4);
	cout << ret << endl;
	ret = t14.longestCommonPrefix(strs5);
	cout << ret << endl;
	getchar();
}