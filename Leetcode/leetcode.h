#pragma once
#include <iostream> 　　　	//数据流输入／输出
#include <string>　　　　　	//字符串类
#include <cstring> 　　　　//字符串处理
#include <vector>　　　　　	//STL 动态数组容器
#include <iterator>        //STL迭代器
#include <map>
#include <list>　　　　　　//STL 线性列表容器

#include <ctime> 　　　　　//定义关于时间的函数
#include <cmath> 　　　　　//定义数学函数
#include <algorithm>　　　 //STL 通用算法

//#define DEBUG_CODE;
using namespace std;

void T0_test();
void T1_test();
void T2_test();
void T3_test();

typedef void (*SOLVE_PROBLEM)(void);

typedef struct
{
	int index;
	SOLVE_PROBLEM func;
}FUNC_INDEX;
