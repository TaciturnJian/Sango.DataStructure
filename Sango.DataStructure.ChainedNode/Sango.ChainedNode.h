/*
	Author: ����Sango
	Brief: �ṩ����˫����������Ͷ��塢�궨�塢�꺯��
*/

#ifndef SANGO_CHAINED_NODE
#define SANGO_CHAINED_NODE

#include "Sango.CodeHelper.Generic.h"

//˫������
typedef struct _ChainedNode {
	ElementPointer element_pointer;
	struct _ChainedNode *last, *next;
} ChainedNode, *ChainedNodePointer;

#define SANGO_CHAINED_NODE_SIZE sizeof(ChainedNode)
#define MallocChainedNode() SangoMalloc(ChainedNode)
#define MallocChainedNodeN(count) SangoMallocN(ChainedNode, count)

#endif
