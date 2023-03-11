/*
	Author: 三苟Sango
	Brief: 提供关于双向链表的扩展函数（基本功能）
*/

#ifndef SANGO_CHAINED_NODE_EXTENSION
#define SANGO_CHAINED_NODE_EXTENSION

#include "Sango.ChainedNode.h"

#pragma region 链表的创建

ChainedNodePointer CreateChainedNode(ElementPointer element);

ChainedNodePointer CreateChainedNode_SimpleCopyElement(ElementPointer element);

#pragma endregion

#pragma region 连接节点

void Connect2Nodes(ChainedNodePointer last, ChainedNodePointer next);

void Connect3Nodes(ChainedNodePointer last, ChainedNodePointer mid, ChainedNodePointer next);

#pragma endregion

#pragma region 移除/销毁节点

/// <summary>
/// 断开节点，该函数不负责销毁节点的内存
/// </summary>
/// <param name="node"></param>
/// <returns></returns>
ChainedNodePointer RemoveNode(ChainedNodePointer node);

/// <summary>
/// 销毁节点，该函数不负责断开节点之间的连接
/// </summary>
/// <param name="node"></param>
void DestroyNode(ChainedNodePointer node);

/// <summary>
/// 连续调用RemoveNode和DestroyNode
/// </summary>
/// <param name="node"></param>
void RemoveAndDestroyNode(ChainedNodePointer node);

#pragma endregion

#endif
