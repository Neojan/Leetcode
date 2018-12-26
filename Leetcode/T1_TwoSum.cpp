#include "leetcode.h"

/*
1. Two Sum
https://leetcode.com/problems/two-sum/

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> retNums;
	int i = 0;
	int j = 0;
#ifdef DEBUG_CODE
	bool found = false;
	if (nums.size() < 2) {
		cout << "wrong data!\n";	
		//Default return value, no result or wrong data
		retNums.push_back(0);
		retNums.push_back(0);
		return retNums;
	}
#endif
	for (i; i < nums.size() - 1; i++) {
		j = i + 1;
		for (j; j < nums.size(); j++) {
			if (nums[i] + nums[j] == target) {
				retNums.push_back(i);
				retNums.push_back(j);
#ifdef DEBUG_CODE
				found = true;
#endif
				break;
			}
		}
	}
#ifdef DEBUG_CODE
	if (found) {
		cout << "Found!\n";
	}
	else {
		cout << "Not found\n";
		//Default return value, no result or wrong data
		retNums.push_back(0);
		retNums.push_back(0);
	}
#endif
	return retNums;
}

#if 0
/*Other ones solution , using Hash maps*/
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> map;
	int n = (int)nums.size();
	for (int i = 0; i < n; i++) {
		auto p = map.find(target - nums[i]);
		if (p != map.end()) {
			return{ p->second + 1, i + 1 };
		}
		map[nums[i]] = i;
	}
}
#endif

void T1_test()
{
	int testNums[4] = { 2, 7, 11, 15 };
	int target = 0;
	vector<int> nums;
	vector<int> retNums;
	for (int i = 0; i < sizeof(testNums) / sizeof(int); i++) {
		nums.push_back(testNums[i]);
	}

	cout << "Please input your target!\n";
	cin >> target;

	retNums = twoSum(nums, target);
	if (retNums.size())
	{
		for (int i = 0; i < retNums.size(); i++) {
			cout << retNums[i] << endl;
		}
	}
	else
	{
		cout << "No result for target!" << endl;
	}

	getchar();
}