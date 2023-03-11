/*
	Author: ����Sango
	Brief: �ṩ�������Ա�����Ͷ��塢�궨�塢�꺯��
*/

#ifndef SANGO_LINEAR_LIST
#define SANGO_LINEAR_LIST

#include "Sango.CodeHelper.Generic.h"

//���Ա�
typedef struct _LinearList {
	//���Ա���������
	int max_capacity;

	//��ǰ�洢�����ݸ���
	int count;

	//�ڲ���Ԫ���б�
	ElementPointer element_list;
} LinearList, *LinearListPointer;

#define SANGO_LINEAR_LIST_SIZE sizeof(ChainedNode)
#define MallocList() SangoMalloc(LinearList)
#define CheckValidIndexInLinearList(index, list) ((index >= 0) && (index < list.max_capacity))
#define CheckValidIndexInLinearListPointer(index, list) ((index >= 0) && (index < list->max_capacity))

#endif
