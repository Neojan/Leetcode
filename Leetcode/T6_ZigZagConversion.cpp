#include "leetcode.h"

/*
6. ZigZag Conversion
https://leetcode.com/problems/zigzag-conversion/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

class Solution {
public:
	string convert(string s, int numRows) {
		int i = 0;
		int j = 0;
		int k = 0;
		if ((1 == numRows) || (s.length() == numRows))
		{
			return s;
		}

		int numCol = s.length()  / (numRows - 1) + 1;
		//cout << numRows << "\t" << numCol << endl;
		string ret(s.length(), 0);
		vector<vector<char> > totalArray(numRows, vector<char>(numCol));
		//assign default value 0
		for (i = 0; i < numRows; i++)
		{
			for (j = 0; j < numCol; j++)
			{
				totalArray[i][j] = 0;
			}
		}
		i = 0;
		j = 0;
		while (k < s.length())
		{
			while (i < numRows && k < s.length())
			{
				totalArray[i++][j] = s[k++];
			}
			i--;
			i--;
			++j;
			while (i > 0 && k < s.length())
			{
				totalArray[i--][j] = s[k++];
			}
			j++;
		}
		k = 0;
		for (i = 0; i < numRows; i++)
		{
			for (j = 0; j < numCol; j++)
			{
				if (totalArray[i][j])
				{
					ret[k++] = totalArray[i][j];
				}
			}
		}
		return ret;
	}
};

void T6_test()
{
	Solution t6;
	string ret;
	string s1("PAYPALISHIRING");
	//string s1("ABCDEFGHI");

	ret = t6.convert(s1, 4);
	cout << ret.c_str() << endl;

	ret = t6.convert(s1,3);
	cout << ret.c_str() << endl;

	ret = t6.convert(s1, 2);
	cout << ret.c_str() << endl;

	ret = t6.convert(s1, 1);
	cout << ret.c_str() << endl;

	getchar();
}