#include "leetcode.h"

/*
4. Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		//This is not a correct answer for O(log (m+n))
		int i = 0;
		int j = 0;
		int k = 0;
		double mid = 0;
		vector<int> nums3(nums1.size() + nums2.size());
		while (i < nums1.size() && j < nums2.size())
		{
			nums3[k++] = (nums1[i] <= nums2[j]) ? nums1[i++] : nums2[j++];
		}
		while (i < nums1.size())
		{
			nums3[k++] = nums1[i++];
		}
		while (j < nums2.size())
		{
			nums3[k++] = nums2[j++];
		}

		//for (i = 0; i < nums3.size(); i++)
		//{
		//	cout << nums3[i] << " " << endl;
		//}
		//cout << endl;

		if (nums3.size() % 2)
		{
			mid = (double)(nums3[nums3.size() / 2]);
		}
		else
		{
			mid = (double)(nums3[nums3.size() / 2] + nums3[nums3.size() / 2 - 1]) / 2;
		}

		//cout << mid << endl;

		return mid;
	}
};

void T4_test(void)
{
	Solution t4;
	vector<int> v1;
	vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v2.push_back(3);
	v2.push_back(4);

	double mid = 0;
	mid = t4.findMedianSortedArrays(v1, v2);
	cout << mid << endl;
	getchar();
}