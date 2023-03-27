#pragma once

#ifndef SANGO_LINKED_NODE_EXTENSION
#define SANGO_LINKED_NODE_EXTENSION

#include "Sango.LinkedNode.h"

#pragma region 链表的创建

LinkedNodePointer CreateLinkedNode(ElementPointer element);

LinkedNodePointer CreateLinked_SimpleCopyElement(ElementPointer element);

#pragma endregion

#pragma region 连接节点

void Connect2LinkedNodes(LinkedNodePointer last, LinkedNodePointer next);

void Connect3LinkedNodes(LinkedNodePointer last, LinkedNodePointer mid, LinkedNodePointer next);

void InseartLinkedNode(LinkedNodePointer node, LinkedNodePointer targetToInseart);

#pragma endregion

#pragma region 移除/销毁节点

/// <summary>
/// 断开节点，该函数不负责销毁节点的内存
/// </summary>
/// <param name="node"></param>
/// <returns></returns>
LinkedNodePointer RemoveLinkedNode(LinkedNodePointer last, LinkedNodePointer target);

/// <summary>
/// 销毁节点，该函数不负责断开节点之间的连接
/// </summary>
/// <param name="node"></param>
void DestroyLinkedNode(LinkedNodePointer node);

/// <summary>
/// 连续调用RemoveNode和DestroyNode
/// </summary>
/// <param name="node"></param>
void RemoveAndDestroyLinkedNode(LinkedNodePointer last, LinkedNodePointer target);

#pragma endregion

void ReverseLoopedNode(LinkedNodePointer current);

#endif
