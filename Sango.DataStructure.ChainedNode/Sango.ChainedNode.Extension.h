/*
	Author: ����Sango
	Brief: �ṩ����˫���������չ�������������ܣ�
*/

#ifndef SANGO_CHAINED_NODE_EXTENSION
#define SANGO_CHAINED_NODE_EXTENSION

#include "Sango.ChainedNode.h"

#pragma region ����Ĵ���

ChainedNodePointer CreateChainedNode(ElementPointer element);

ChainedNodePointer CreateChainedNode_SimpleCopyElement(ElementPointer element);

#pragma endregion

#pragma region ���ӽڵ�

void Connect2Nodes(ChainedNodePointer last, ChainedNodePointer next);

void Connect3Nodes(ChainedNodePointer last, ChainedNodePointer mid, ChainedNodePointer next);

#pragma endregion

#pragma region �Ƴ�/���ٽڵ�

/// <summary>
/// �Ͽ��ڵ㣬�ú������������ٽڵ���ڴ�
/// </summary>
/// <param name="node"></param>
/// <returns></returns>
ChainedNodePointer RemoveNode(ChainedNodePointer node);

/// <summary>
/// ���ٽڵ㣬�ú���������Ͽ��ڵ�֮�������
/// </summary>
/// <param name="node"></param>
void DestroyNode(ChainedNodePointer node);

/// <summary>
/// ��������RemoveNode��DestroyNode
/// </summary>
/// <param name="node"></param>
void RemoveAndDestroyNode(ChainedNodePointer node);

#pragma endregion

#endif
