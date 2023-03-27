#include "Sango.LinkedNode.Extension.h"

LinkedNodePointer CreateLinkedNode(ElementPointer element) {
	LinkedNodePointer node = MallocLinkedNode();
	ReturnXWhenNullPointer(0, node);

	node->element = element;
	node->next = 0;
	return node;
}

LinkedNodePointer CreateLinked_SimpleCopyElement(ElementPointer element) {
	ReturnXWhenNullPointer(0, element);
	ElementPointer element_copied = (ElementType *)(malloc(sizeof(ElementType)));
	ReturnXWhenNullPointer(0, element_copied);

	memcpy(element_copied, element, SANGO_ELEMENT_SIZE);
	LinkedNodePointer node = CreateLinkedNode(element_copied);
	if NullPointer(node) {
		free(element_copied);
		return 0;
	}

	return node;
}

void Connect2LinkedNodes(LinkedNodePointer last, LinkedNodePointer next) {
	if NotNullPointer(last) {
		last->next = next;
	}
}

void Connect3LinkedNodes(LinkedNodePointer last, LinkedNodePointer mid, LinkedNodePointer next) {
	Connect2LinkedNodes(last, mid);
	Connect2LinkedNodes(mid, next);
}

LinkedNodePointer RemoveLinkedNode(LinkedNodePointer last, LinkedNodePointer target) {
	ReturnXWhenNullPointer(0, target);
	ExecuteXWhenNotNullPointer(last->next = target->next, last);

	return target;
}

void InseartLinkedNode(LinkedNodePointer node, LinkedNodePointer targetToInseart) {
	ExecuteXWhenNotNullPointer(Connect2LinkedNodes(targetToInseart, node->next->next), node->next);
}

void DestroyLinkedNode(LinkedNodePointer node) {
	ReturnWhenNullPointer(node);
	FreeWhenNotNullPointer(node->element);
	free(node);
}

void RemoveAndDestroyLinkedNode(LinkedNodePointer last, LinkedNodePointer target) {
	DestroyLinkedNode(RemoveLinkedNode(last, target));
}

void ReverseLoopedNode(LinkedNodePointer current) {
	LinkedNodePointer
		last = 0,
		next;

	while (current) {
		next = current->next;
		current->next = last;
		last = current;
		current = next;
	}
}
