#pragma once
#include <iostream> ������	//���������룯���
#include <string>����������	//�ַ�����
#include <cstring> ��������//�ַ�������
#include <vector>����������	//STL ��̬��������
#include <iterator>        //STL������
#include <map>
#include <list>������������//STL �����б�����

#include <ctime> ����������//�������ʱ��ĺ���
#include <cmath> ����������//������ѧ����
#include <algorithm>������ //STL ͨ���㷨

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
