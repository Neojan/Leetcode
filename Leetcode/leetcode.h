#pragma once
#include <iostream> ������	//���������룯���
#include <string>����������	//�ַ�����
#include <sstream>
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

void T0_test(void);
void T1_test(void);
void T2_test(void);
void T3_test(void);
void T4_test(void);
void T5_test(void);
void T6_test(void);
void T7_test(void);
void T8_test(void);
void T9_test(void);
void T11_test(void);
void T12_test(void);
void T13_test(void);
void T14_test(void);

typedef void (*SOLVE_PROBLEM)(void);

typedef struct
{
	int index;
	SOLVE_PROBLEM func;
}FUNC_INDEX;
