/*
	Author: 三苟Sango
	Brief: 提供关于双向链表的类型定义、宏定义、宏函数
*/

#ifndef SANGO_CHAINED_NODE
#define SANGO_CHAINED_NODE

#include "Sango.CodeHelper.Generic.h"

//双向链表
typedef struct _ChainedNode {
	ElementPointer element_pointer;
	struct _ChainedNode *last, *next;
} ChainedNode, *ChainedNodePointer;

#define SANGO_CHAINED_NODE_SIZE sizeof(ChainedNode)
#define MallocChainedNode() SangoMalloc(ChainedNode)
#define MallocChainedNodeN(count) SangoMallocN(ChainedNode, count)

#endif
