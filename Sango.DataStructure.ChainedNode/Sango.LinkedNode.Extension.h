#pragma once

#ifndef SANGO_LINKED_NODE_EXTENSION
#define SANGO_LINKED_NODE_EXTENSION

#include "Sango.LinkedNode.h"

#pragma region ����Ĵ���

LinkedNodePointer CreateLinkedNode(ElementPointer element);

LinkedNodePointer CreateLinked_SimpleCopyElement(ElementPointer element);

#pragma endregion

#pragma region ���ӽڵ�

void Connect2LinkedNodes(LinkedNodePointer last, LinkedNodePointer next);

void Connect3LinkedNodes(LinkedNodePointer last, LinkedNodePointer mid, LinkedNodePointer next);

void InseartLinkedNode(LinkedNodePointer node, LinkedNodePointer targetToInseart);

#pragma endregion

#pragma region �Ƴ�/���ٽڵ�

/// <summary>
/// �Ͽ��ڵ㣬�ú������������ٽڵ���ڴ�
/// </summary>
/// <param name="node"></param>
/// <returns></returns>
LinkedNodePointer RemoveLinkedNode(LinkedNodePointer last, LinkedNodePointer target);

/// <summary>
/// ���ٽڵ㣬�ú���������Ͽ��ڵ�֮�������
/// </summary>
/// <param name="node"></param>
void DestroyLinkedNode(LinkedNodePointer node);

/// <summary>
/// ��������RemoveNode��DestroyNode
/// </summary>
/// <param name="node"></param>
void RemoveAndDestroyLinkedNode(LinkedNodePointer last, LinkedNodePointer target);

#pragma endregion

void ReverseLoopedNode(LinkedNodePointer current);

#endif
