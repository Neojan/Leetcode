#include "leetcode.h"

/*
3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int i = 0, j = 1, k = 0;
		int breakOne;
		int maxString = 1;
		int length = s.length();
		if (length == 0 || length == 1)
		{
			return length;
		}
		for (i = 0; i < length - maxString + 1; i++)
		{
			for (j; j < length; j++)
			{
				for (k = i; k < j; k++)
				{
					if (s[j] == s[k])
					{
						break;
					}
				}
				if (k == j)
				{
					breakOne = j;//From max string start.
					maxString = max(maxString, j - i + 1);
				}
				else
				{
					break;
				}
			}
		}
		return maxString;
	}
};

void T3_test()
{
	Solution t3;
	string testS1("abcabcbb");
	string testS2("bbbbb");
	string testS3("pwwkew");
	string testS4("");

	cout << "The first test stirng is [" << testS1.c_str() << "], which's max sub string len is " << t3.lengthOfLongestSubstring(testS1) << endl;
	cout << "The second test stirng is [" << testS2.c_str() << "], which's max sub string len is " << t3.lengthOfLongestSubstring(testS2) << endl;
	cout << "The third test stirng is [" << testS3.c_str() << "], which's max sub string len is " << t3.lengthOfLongestSubstring(testS3) << endl;
	cout << "The fourth test stirng is [" << testS4.c_str() << "], which's max sub string len is " << t3.lengthOfLongestSubstring(testS4) << endl;

	getchar();
}