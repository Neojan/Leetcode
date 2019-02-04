#include "leetcode.h"
/*
T11_ContainerWithMostWater.cpp
11. Container With Most Water
https://leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

class Solution {
public:
	int maxArea(vector<int>& height) {
		int i = 0;
		int j = 0;
		int container = 0;
		int area = 0;
		for (i = 0; i < height.size() - 1; i++)
		{
			for (j = i + 1; j < height.size(); j++)
			{
				area = min(height[j], height[i]) * (j - i);
				container = max(area, container);
			}
		}

		return container;
	}
};


void T11_test()
{
	Solution t11;
	vector <int> t1{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	vector <int> t2{ 1, 0 };

	int area = 0;

	area = t11.maxArea(t1);
	cout << "Max area is " << area << endl;

	area = t11.maxArea(t2);
	cout << "Max area is " << area << endl;

	getchar();
}