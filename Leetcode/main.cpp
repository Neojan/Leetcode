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
