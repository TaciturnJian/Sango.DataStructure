#include "Sango.ChainedNode.Extension.h"

#pragma region 链表的创建

ChainedNodePointer CreateChainedNode(ElementPointer element) {
	SimpleMallocNode(node);
	ReturnXWhenNullPointer(0, node);

	node->element_pointer = element;
	Connect3Nodes(0, node, 0);
	return node;
}

ChainedNodePointer CreateChainedNode_SimpleCopyElement(ElementPointer element) {
	ReturnXWhenNullPointer(0, element);
	SimpleMallocElement(element_copied);
	ReturnXWhenNullPointer(0, element_copied);

	memcpy(element_copied, element, SANGO_ELEMENT_SIZE);
	return CreateChainedNode(element_copied);
}

#pragma endregion

#pragma region 连接节点

void Connect2Nodes(ChainedNodePointer last, ChainedNodePointer next) {
	ExecuteXWhenNotNullPointer(last, last->next = next);
	ExecuteXWhenNotNullPointer(next, next->last = last);
}

void Connect3Nodes(ChainedNodePointer last, ChainedNodePointer mid, ChainedNodePointer next) {
	Connect2Nodes(last, mid);
	Connect2Nodes(mid, next);
}

#pragma endregion

#pragma region 移除/销毁节点

ChainedNodePointer RemoveNode(ChainedNodePointer node) {
	ReturnXWhenNullPointer(0, node);
	Connect2Nodes(node->last, node->next);
	Connect3Nodes(0, node, 0);
	return node;
}

void DestroyNode(ChainedNodePointer node) {
	ReturnWhenNullPointer(node);
	FreeWhenNotNullPointer(node->element_pointer);
	free(node);
}

void RemoveAndDestroyNode(ChainedNodePointer node) {
	ReturnWhenNullPointer(node);
	DestroyNode(RemoveNode(node));
}

#pragma endregion
