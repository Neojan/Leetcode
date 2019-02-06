#include "leetcode.h"

void T0_test() { cout << "this is a null function\n"; getchar(); };

FUNC_INDEX solveProblemList[] =
{
	{ 0, T0_test },
	{ 1, T1_test },
	{ 2, T2_test },
	{ 3, T3_test },
	{ 4, T4_test },
	{ 5, T5_test },
	{ 6, T6_test },
	{ 7, T7_test },
	{ 8, T8_test },
	{ 9, T9_test },
	{ 10, T9_test },
	{ 11, T11_test },
	{ 12, T12_test },
	{ 13, T13_test },
	{ 14, T14_test },
};

int main(void)
{
	int index;
	cout << "Please input problem number!\n";
	cin >> index;
	if (index < 0 || index >=(sizeof(solveProblemList) / sizeof(FUNC_INDEX)))
	{
		cout << "Invalid index " << index << endl;
	}
	else
	{
		solveProblemList[index].func();
	}

	cout << "Problem " << index << " is end!" << endl;
	
	getchar();
	return 0;
}
