/*
	Author: 三苟Sango
	Brief: 提供关于线性表的类型定义、宏定义、宏函数
*/

#ifndef SANGO_LINEAR_LIST
#define SANGO_LINEAR_LIST

#include "Sango.CodeHelper.Generic.h"

//线性表
typedef struct _LinearList {
	//线性表的最大容量
	int max_capacity;

	//当前存储的数据个数
	int count;

	//内部的元素列表
	ElementPointer element_list;
} LinearList, *LinearListPointer;

#define SANGO_LINEAR_LIST_SIZE sizeof(ChainedNode)
#define MallocList() SangoMalloc(LinearList)
#define CheckValidIndexInLinearList(index, list) ((index >= 0) && (index < list.max_capacity))
#define CheckValidIndexInLinearListPointer(index, list) ((index >= 0) && (index < list->max_capacity))

#endif
